#include "includeMoving/Warrior.h"

void Warrior::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

void Warrior::DirectionImg(int dir)
{
	m_sprite.setTexture(*Resources::instance().getTexture(load_Warrior, dir));
}