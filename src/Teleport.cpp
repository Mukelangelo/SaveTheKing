#include "Teleport.h"

void Teleport::handleCollision(GameObject& player)
{
	m_dispatched = CollisionStatus::Good;
	if (typeid(player) == typeid(Mage) /* || m_tpUsed*/)
	{
		m_dispatched = CollisionStatus::Not_Valid;
		return;
	}
	//m_tpUsed = true;
}