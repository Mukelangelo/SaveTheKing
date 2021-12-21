#pragma once

#include "MovingObject.cpp"

class Warrior : MovingObject
{
public:
	using MovingObject::MovingObject;
	bool isOgre();

private:
};