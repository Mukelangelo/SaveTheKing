#pragma once

#include "includeMoving/MovingObject.h"


class Warrior : public MovingObject
{
public:
	Warrior(sf::Vector2f loc, const sf::Texture& texture);
	virtual void handleCollision(GameObject& gameObject) override;

	virtual void DirectionImg(int dir) override;

private:
};