#include "Thief.h"

Thief::Thief(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(load_Thief, loc, texture)
{}


/*bool Thief::onSpecialTile()
{
	if (m_location == m_throne)
		return true;
}
*/