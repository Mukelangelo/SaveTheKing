#pragma once

#include "MovingObject.h"
#include <cstdlib>

class Gnome : public MovingObject
{
public:
	Gnome(sf::Vector2f loc, const sf::Texture& texture);
	//virtual bool onSpecialTile() ; // on Throne
	void setDirection(sf::Keyboard::Key key) override;
	virtual void handleCollision(MovingObject& player) override;
	void setRandomDirection();

private:

};