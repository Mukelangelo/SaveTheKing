#include "includeMoving/King.h"

void King::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

void King::DirectionImg(int dir)
{
	m_sprite.setTexture(*Resources::instance().getTexture(load_King , dir));
}