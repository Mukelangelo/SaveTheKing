#pragma once

#include "MovingObject.cpp"

class Mage : MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual bool onSpecialTile() override; // on Fire tile

private:
};