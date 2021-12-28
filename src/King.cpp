#include "King.h"

King::King(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}

void King::handleCollision(MovingObject& player)
{
	if (&player == this) return;
	//player.handleCollision(*this);
}

/*void handleCollision(GameObject& gameObject) override
{
    if (&gameObject == this) return;
    gameObject.handleCollision(*this);
}

void King::handleCollision(Throne& gameObject)
{
	m_win = true;
}
*/

/*bool King::onSpecialTile()
{
	if (m_location == m_throne)
		return true;
}
*/