#pragma once

#include "MovingObject.cpp"

class Thief : MovingObject
{
public:
	using MovingObject::MovingObject;
	bool isGate();
	bool isKey();

private:
	bool m_key;
};