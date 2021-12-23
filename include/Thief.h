#pragma once

#include "MovingObject.h"


class Thief : public MovingObject
{
public:
	Thief(sf::Vector2f loc, const sf::Texture& texture);
	//virtual bool onSpecialTile() ; // on Throne
	bool hasKey();

private:
	bool m_key;
};