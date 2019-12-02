#pragma once
#ifndef __Collider__
#define __Collider__

#include "ColliderShape.h"

class Collider
{
public :
	Collider();
	virtual ~Collider();

protected :
	ColliderShape colliderShape;
};

#endif
