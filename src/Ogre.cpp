#include "Ogre.h"

void Ogre::handleCollision(GameObject& player)
{
	m_dispatched = false;
	if (typeid(player) == typeid(Warrior))
	{
		auto texture = sf::Texture();
		texture.loadFromFile("key.png");
		m_sprite.setTexture(texture);
		m_dispatched = true;
	}
}