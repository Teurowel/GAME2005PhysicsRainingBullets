#pragma once
#ifndef __Circle_Collider__
#define __Circle_Collider__

#include "Collider.h"
#include "GLM/vec2.hpp"

class CircleCollider : public Collider
{
public :
	CircleCollider(glm::vec2 centre = glm::vec2(0.f, 0.f), int radius = 0)
		:centre(centre), radius(radius)
	{
		
	}
	~CircleCollider() {}

	glm::vec2 centre;
	float radius;
};

#endif