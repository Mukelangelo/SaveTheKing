#include "Thief.h"

Thief::Thief(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)//, m_key(false)
{}

void Thief::setKey(bool status)
{
	m_key = status;
}

bool Thief::getKey()
{
	return m_key;
}

void Thief::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

void Thief::handleCollision(Gate& gameObject)
{
	if (m_key) // add change sprite
		return;
	else
		this->setLocation(this->getLastLoc());
}

void Thief::handleCollision(Key& gameObject)
{
	if (!m_key)
		m_key = true;
}

/*
void Thief::handleCollision(Wall& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Thief::handleCollision(Fire& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Thief::handleCollision(Throne& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Thief::handleCollision(Ogre& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Thief::handleCollision(Teleport& gameObject)
{
	m_onTP = true;
}
*/



