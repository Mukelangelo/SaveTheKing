#include "Warrior.h"

Warrior::Warrior(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}


/*bool Warrior::onSpecialTile()
{
	if (m_location == m_throne)
		return true;
}
*/

void Warrior::handleCollision(MovingObject& player)
{
	if (&player == this) return;
	player.handleCollision(*this);
}
