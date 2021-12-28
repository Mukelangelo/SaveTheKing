#include "Gate.h"

void Gate::handleCollision(GameObject& player)
{
	if (typeid(player) == typeid(Thief))
	{
		auto texture = sf::Texture();
		texture.loadFromFile("key.png");
		m_sprite.setTexture(texture);
	}

}
