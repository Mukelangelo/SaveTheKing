#include "Throne.h"

void Throne::handleCollision(GameObject& player)
{
	if (typeid(player) == typeid(King))
	{
		m_sprite.setColor(sf::Color::Transparent);
	}
	
}

