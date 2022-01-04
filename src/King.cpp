#include "King.h"

King::King(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}

void King::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

void King::handleCollision(Wall& gameObject)
{
	m_location = this->getLastLoc();
}

void King::handleCollision(Throne& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void King::handleCollision(Gate& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void King::handleCollision(Fire& gameObject) 
{
	this->setLocation(this->getLastLoc());
}

void King::handleCollision(Ogre& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void King::handleCollision(Teleport& gameObject) 
{
	m_onTP = true;
}