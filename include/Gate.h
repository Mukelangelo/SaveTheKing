#pragma once

#include "StaticObject.h"
#include "Thief.h"
class Gate : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual void handleCollision(GameObject& player) override;

private:
};