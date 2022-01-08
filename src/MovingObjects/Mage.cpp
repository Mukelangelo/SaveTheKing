#include "includeMoving/Mage.h"

Mage::Mage(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}

void Mage::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

void Mage::DirectionImg(int dir)
{
	switch (dir)
	{
	case Up:
		m_sprite.setTexture(*Resources::instance().getTexture(load_MageUp));
		break;

	case Down:
		m_sprite.setTexture(*Resources::instance().getTexture(load_MageDown));
		break;

	case Left:
		m_sprite.setTexture(*Resources::instance().getTexture(load_Mage));
		m_sprite.scale(-1, 1);
		break;
	case Right:
		m_sprite.setTexture(*Resources::instance().getTexture(load_Mage));
		break;
	default:
		break;
	}
}