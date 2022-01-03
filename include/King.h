#pragma once

#include "MovingObject.h"
#include <Throne.h>

class King : public MovingObject
{
public:
	King(sf::Vector2f loc, const sf::Texture& texture);
	virtual void handleCollision(MovingObject& player) override ;

private:
};