#pragma once

#include "includeMoving/MovingObject.h"

class King : public MovingObject
{
public:
	King(sf::Vector2f loc, const sf::Texture& texture);
	virtual void handleCollision(GameObject& gameObject) override;
	
	virtual void DirectionImg(int dir) override;

private:
};