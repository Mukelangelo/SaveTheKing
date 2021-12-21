#pragma once

#include "MovingObject.cpp"

class King : MovingObject
{
public:
	King(sf::vector2f throneLoc);
	bool onThrone();

private:
	sf::vector2f m_throne; // do we really need it here?
};