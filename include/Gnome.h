#pragma once

#include "MovingObject.h"


class Gnome : public MovingObject
{
public:
	Gnome(sf::Vector2f loc, const sf::Texture& texture);
	//virtual bool onSpecialTile() ; // on Throne

	virtual void handleCollision(MovingObject& player) override;

private:
};