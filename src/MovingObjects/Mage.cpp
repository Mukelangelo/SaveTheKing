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
	m_sprite.setTexture(*Resources::instance().getTexture(load_Mage , dir));
}