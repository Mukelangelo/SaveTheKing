#include "Gnome.h"
#include <iostream>

Gnome::Gnome(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{
	m_speedPerSecond = 170.f;
	srand(time(NULL));
}

void Gnome::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

/*
void Gnome::handleCollision(Wall& gameObject)
{
	m_location = this->getLastLoc();
}


void Gnome::handleCollision(Throne& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Gnome::handleCollision(Gate& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Gnome::handleCollision(Fire& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Gnome::handleCollision(Ogre& gameObject)
{
	this->setLocation(this->getLastLoc());
}

void Gnome::handleCollision(Teleport& gameObject)
{
	m_onTP = true;
}
*/

void Gnome::setDirection(sf::Keyboard::Key key)
{
	setRandomDirection();
}

void Gnome::setRandomDirection()
{
	int direction = rand() % 4;
	switch (direction)
	{
	case 0:
		m_direction = sf::Vector2f(0, -1); break;
	case 1:
		m_direction = sf::Vector2f(-1, 0); break;
	case 2:
		m_direction = sf::Vector2f(0, 1); break;
	case 3:
		m_direction = sf::Vector2f(1, 0); break;
	}
}