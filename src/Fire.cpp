#include "Fire.h"

void Fire::handleCollision(GameObject& player)
{
	m_dispatched = false;
	if (typeid(player) == typeid(Mage))
		m_dispatched = true;
}