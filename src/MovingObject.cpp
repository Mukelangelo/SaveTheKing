#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f loc, const sf::Texture& texture)
	: GameObject(loc, texture)
{}

void MovingObject::movePlayer(sf::Time deltaTime)
{
	const auto speedPerSecond = 120.f;
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