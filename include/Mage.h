#pragma once

#include "MovingObject.h"


class Mage : public MovingObject
{
public:
	Mage(sf::Vector2f loc, const sf::Texture& texture);
	virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Throne& gameObject) override;
	virtual void handleCollision(Gate& gameObject) override;
	virtual void handleCollision(Fire& gameObject) override;
	virtual void handleCollision(Key& gameObject) override {};
	virtual void handleCollision(Ogre& gameObject) override;
	virtual void handleCollision(Teleport& gameObject) override;

private:
};