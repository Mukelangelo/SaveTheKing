#pragma once

#include "StaticObject.h"
#include "Warrior.h"

class Ogre : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual void handleCollision(GameObject& player) override;

private:
};