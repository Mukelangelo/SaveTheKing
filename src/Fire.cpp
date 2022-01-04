#include "Fire.h"

void Fire::handleCollision(GameObject& player)
{
	m_dispatched = CollisionStatus::Good;
	if (typeid(player) != typeid(Mage))
		m_dispatched = CollisionStatus::Not_Valid;
	else if (typeid(player) == typeid(Mage))
		m_dispatched = CollisionStatus::Destroy;
}
