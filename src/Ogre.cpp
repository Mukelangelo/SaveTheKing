#include "Ogre.h"

void Ogre::handleCollision(GameObject& player)
{
	if (typeid(player) == typeid(Warrior))
	{
		m_sprite.setColor(sf::Color::Transparent);
	}

}