#include "King.h"

King::King(sf::Vector2f throneLoc, sf::Vector2f loc, const sf::Texture& texture)
	:m_throne(throneLoc), MovingObject(load_King, loc, texture)
{
}


/*bool King::onSpecialTile()
{
	if (m_location == m_throne)
		return true;
}
*/