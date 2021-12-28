#include "Fire.h"

void Fire::handleCollision(GameObject& player)
{
	if (typeid(player) == typeid(Mage))
	{
		m_sprite.setColor(sf::Color::Transparent);
	}

}