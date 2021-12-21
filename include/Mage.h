#pragma once

#include "MovingObject.cpp"

class Mage : MovingObject
{
public:
	using MovingObject::MovingObject;
	bool isFire();

private:
};