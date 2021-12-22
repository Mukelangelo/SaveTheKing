#pragma once
#include "macros.h"
#include "MovingObject.cpp"


class King : public MovingObject
{
public:
	King(sf::vector2f throneLoc);
	virtual bool onSpecialTile() override; // on Throne

private:
	sf::vector2f m_throne; // do we really need it here?
};