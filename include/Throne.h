#pragma once

#include "StaticObject.h"
#include "King.h"

class Throne : public StaticObject
{
public:
	using StaticObject::StaticObject;
	void handleCollision(MovingObject& gameObject);

private:
};