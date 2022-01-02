#include "Gnome.h"

Gnome::Gnome(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{
	 //m_speedPerSecond = 170.f;
}

void Gnome::handleCollision(MovingObject& player)
{
	if (&player == this) return;

}


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