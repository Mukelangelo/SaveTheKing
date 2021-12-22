#pragma once

#include "MovingObject.h"


class King : public MovingObject
{
public:
	King(sf::Vector2f throneLoc, sf::Vector2f loc, const sf::Texture& texture);
	virtual bool onSpecialTile() override; // on Throne

private:
	sf::Vector2f m_throne; // do we really need it here?
};