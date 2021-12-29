#pragma once

#include "StaticObject.h"
#include "King.h"

class Throne : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual void handleCollision(GameObject& player) override;
	
private:
};