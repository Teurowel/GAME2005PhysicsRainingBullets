#pragma once
#ifndef __Bullet__
#define __Bullet__

#include <vector>
#include "DisplayObject.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Tile.h"
#include "Scene.h"

class Bullet :
	public DisplayObject
{
public:
	Bullet();
	~Bullet();

	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;

	void Reset();

	void SetSpeed(float fSpeed) { m_fSpeed = fSpeed; }
	int GetSpeedRange() const { return m_iSpeedRange; }
private :
	float m_fSpeed;
	int m_iSpeedRange;
};


#endif /* defined (__Ship__) */

