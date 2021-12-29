#include "Gate.h"

void Gate::handleCollision(GameObject& player)
{
	m_dispatched = false;
	//m_collided = true;
	if (typeid(player) == typeid(Thief))
	{
		auto texture = sf::Texture();
		texture.loadFromFile("key.png");
		m_sprite.setTexture(texture);
		m_dispatched = true;
	}

}
