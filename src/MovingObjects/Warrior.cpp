#include "includeMoving/Warrior.h"

Warrior::Warrior(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}

void Warrior::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

/*
void Warrior::handleCollision(Wall& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Warrior::handleCollision(Throne& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Warrior::handleCollision(Gate& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Warrior::handleCollision(Fire& gameObject) 
{
	this->setLocation(this->getLastLoc());
}

void Warrior::handleCollision(Key& gameObject) {}

void Warrior::handleCollision(Ogre& gameObject){}

void Warrior::handleCollision(Teleport& gameObject) {}

*/