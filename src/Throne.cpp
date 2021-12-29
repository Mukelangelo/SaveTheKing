#include "Throne.h"

void Throne::handleCollision(GameObject& player)
{
	m_dispatched = false;
	if (typeid(player) == typeid(King))
	{
		m_sprite.setColor(sf::Color::Transparent);
		m_dispatched = true;
	}
}

