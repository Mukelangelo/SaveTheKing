#include "Mage.h"

Mage::Mage(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}

void Mage::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

void Mage::handleCollision(Wall& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Mage::handleCollision(Throne& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Mage::handleCollision(Gate& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Mage::handleCollision(Fire& gameObject){}


void Mage::handleCollision(Ogre& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Mage::handleCollision(Teleport& gameObject){}