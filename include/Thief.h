#pragma once

#include "MovingObject.cpp"

class Thief : MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual bool onSpecialTile() override ; // on Gate tile
	bool hasKey();

private:
	bool m_key;
};