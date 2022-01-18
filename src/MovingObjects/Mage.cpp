#include "includeMoving/Mage.h"

void Mage::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

//=======================================================================================
void Mage::DirectionImg(int dir)
{
	m_sprite.setTexture(*Resources::instance().getTexture(load_Mage , dir));
}