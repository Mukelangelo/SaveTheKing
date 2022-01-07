#pragma once

#include "includeMoving/MovingObject.h"
#include <stdlib.h> 
#include <time.h> 

class Gnome : public MovingObject
{
public:
	Gnome(sf::Vector2f loc, const sf::Texture& texture);
	void setDirection(sf::Keyboard::Key key) override;
	virtual void handleCollision(GameObject& gameObject) override;

	/*
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Throne& gameObject) override;
	virtual void handleCollision(Gate& gameObject) override;
	virtual void handleCollision(Fire& gameObject) override;
	virtual void handleCollision(Key& gameObject) override {};
	virtual void handleCollision(Ogre& gameObject) override;
	virtual void handleCollision(Teleport& gameObject) override;
	*/

	void setRandomDirection();

private:
	
};