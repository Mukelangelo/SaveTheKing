#include "includeMoving/King.h"

King::King(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}


void King::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

void King::DirectionImg(int dir)
{
	switch (dir)
	{
	case Up:
		m_sprite.setTexture(*Resources::instance().getTexture(load_KingUp)); 
		break;

	case Down:
		m_sprite.setTexture(*Resources::instance().getTexture(load_KingDown)); 
		break;

	case Left:
		m_sprite.setTexture(*Resources::instance().getTexture(load_King));
		m_sprite.scale(1, -1);
		break;
	case Right:
		m_sprite.setTexture(*Resources::instance().getTexture(load_King));
		break;
	default:
		break;
	}
}