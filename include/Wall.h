#pragma once

#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual void handleCollision(GameObject& player) override;

private:
};