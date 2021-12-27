#include "Thief.h"

Thief::Thief(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}


/*bool Thief::onSpecialTile()
{
	if (m_location == m_throne)
		return true;
}
*/

void Thief::handleCollision(MovingObject& player)
{
	if (&player == this) return;
	player.handleCollision(*this);
}
