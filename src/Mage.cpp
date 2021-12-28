#include "Mage.h"

Mage::Mage(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}

void Mage::handleCollision(MovingObject& player)
{
	if (&player == this) return;
	
}

/*bool Mage::onSpecialTile()
{
	if (m_location == m_throne)
		return true;
}
*/