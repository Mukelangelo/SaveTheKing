#pragma once

#include "includeMoving/MovingObject.h"

class King : public MovingObject
{
public:
	King(sf::Vector2f loc, const sf::Texture& texture);
	virtual void handleCollision(GameObject& gameObject) override;
	
	/*
	virtual void handleCollision(Wall& gameObject);
	virtual void handleCollision(Throne& gameObject) override;
	virtual void handleCollision(Gate& gameObject);
	virtual void handleCollision(Fire& gameObject);
	virtual void handleCollision(Key& gameObject) {};
	virtual void handleCollision(Ogre& gameObject);
	virtual void handleCollision(Teleport& gameObject);
	*/

private:
};