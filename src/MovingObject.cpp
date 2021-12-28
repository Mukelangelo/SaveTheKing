#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f loc, const sf::Texture& texture)
	: GameObject(loc, texture), m_lastLoc(loc)
{}

void MovingObject::movePlayer(sf::Time deltaTime)
{
	const auto speedPerSecond = 80.f;
	m_sprite.move(m_direction * speedPerSecond * deltaTime.asSeconds());
}

void MovingObject::setLocation(const sf::Vector2f& loc)
{
	m_location = loc;
}

void MovingObject::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Up:
		m_direction = sf::Vector2f(0, -1); break;
	case sf::Keyboard::Key::Left:
		m_direction = sf::Vector2f(-1, 0); break;
	case sf::Keyboard::Key::Down:
		m_direction = sf::Vector2f(0, 1); break;
	case sf::Keyboard::Key::Right:
		m_direction = sf::Vector2f(1, 0); break;
	}
}

sf::Vector2f MovingObject::getDirection()
{
	return m_direction;
}

void MovingObject::setLastLoc(sf::Vector2f loc)
{
	m_lastLoc = loc;
}
sf::Vector2f MovingObject::getLastLoc()
{
	return m_lastLoc;
}

void MovingObject::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}