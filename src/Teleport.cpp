#include "Teleport.h"

void Teleport::handleCollision(GameObject& player)
{
	m_dispatched = CollisionStatus::Good;
	if (typeid(player) != typeid(Mage))
	{
		m_dispatched = CollisionStatus::Teleport;
		return;
	}
}