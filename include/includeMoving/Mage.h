#pragma once

#include "includeMoving/MovingObject.h"


class Mage : public MovingObject
{
public:
	Mage(sf::Vector2f loc, const sf::Texture& texture);
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void DirectionImg(int dir) override;

private:
};