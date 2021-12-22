#pragma once

#include "MovingObject.cpp"

class Warrior : MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual bool onSpecialTile() override ; // on Orge

private:
};