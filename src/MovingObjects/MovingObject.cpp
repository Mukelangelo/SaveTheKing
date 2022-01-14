#include "includeMoving/MovingObject.h"

MovingObject::MovingObject(sf::Vector2f loc, const sf::Texture& texture)
	: GameObject(loc, texture), m_lastLoc(loc)
{
	m_speedPerSecond = m_sprite.getScale().x * 180; 
	// make the speed proportional to the sprite size.
}

void MovingObject::movePlayer(sf::Time deltaTime)
{
	m_sprite.move(m_direction * m_speedPerSecond * deltaTime.asSeconds());
	m_location = m_sprite.getPosition();
}

void MovingObject::setLocation(const sf::Vector2f& loc)
{
	m_sprite.setPosition(loc);
	m_location = loc;
}

void MovingObject::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Up:
		m_direction = sf::Vector2f(0, -1); 
		DirectionImg(Up);
		break;

	case sf::Keyboard::Key::Left:
		m_direction = sf::Vector2f(-1, 0); 
		DirectionImg(Left);
		break;
	case sf::Keyboard::Key::Down:
		m_direction = sf::Vector2f(0, 1);
		DirectionImg(Down);
		break;
	case sf::Keyboard::Key::Right:
		m_direction = sf::Vector2f(1, 0);
		DirectionImg(Right);
		break;
	}
}

void MovingObject::setLastLoc()
{
	m_lastLoc = m_location;
}

sf::Vector2f MovingObject::getLastLoc()
{
	return m_lastLoc;
}

void MovingObject::teleported()
{
	m_onTP = !m_onTP;
}

bool MovingObject::isTp()
{
	return m_onTP;
}