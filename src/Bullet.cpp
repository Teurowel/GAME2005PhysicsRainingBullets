#include "Bullet.h"
#include "Game.h"
#include "Util.h"
#include "GLM/gtx/rotate_vector.hpp"
#include "PlayScene.h"
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>

Bullet::Bullet()
{
	TheTextureManager::Instance()->load("../Assets/textures/Bullet.png","Bullet", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Bullet");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(0.0f, 0.0f));
	//setInitialPosition(getPosition());

	setVelocity(glm::vec2(0.0f, 0.0f));
	//setInitialVelocity(getVelocity());
	setAcceleration(glm::vec2(0.0f, 0.0f));

	setIsColliding(false);
	setType(GameObjectType::BULLET);
	setState(State::IDLE);

	m_fSpeed = 0;
	m_iSpeedRange = 10;
}


Bullet::~Bullet()
{
}

void Bullet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	int Width = getWidth();
	int Height = getHeight();

	TheTextureManager::Instance()->draw("Bullet", xComponent - (Width * 0.5f), yComponent - (Height * 0.5f),
		TheGame::Instance()->getRenderer(), 0.f, 255);
}

void Bullet::update()
{
	//move();
	//getParent()->

	StartScene* scene = dynamic_cast<StartScene*>(getParent());
	if (scene != nullptr)
	{
		glm::vec2 NewPos = getPosition();
		NewPos += glm::vec2(0.f, 1.f) * m_fSpeed * (float)scene->GetPPM() * (1.0f / 60.0f);
		setPosition(NewPos);
	}



	if (getPosition().y - (getHeight() * 0.5f) >= Config::SCREEN_HEIGHT || getIsColliding())
	{
		setPosition(glm::vec2((rand() % (Config::SCREEN_WIDTH - 20)) + 10, -10));
		m_fSpeed = rand() % m_iSpeedRange + 1;
		setIsColliding(false);
	}
}

void Bullet::clean()
{
	
}

void Bullet::Reset()
{
	//setPosition(getInitialPosition());
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));

	setIsColliding(false);
}