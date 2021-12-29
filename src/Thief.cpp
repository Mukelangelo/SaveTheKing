#include "Thief.h"

Thief::Thief(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture), m_key(false)
{}

void Thief::setKey(bool status)
{
	m_key = status;
}

bool Thief::getKey()
{
	return m_key;
}

void Thief::handleCollision(MovingObject& player)
{
	if (&player == this) return;
	//player.handleCollision(*this);
}
