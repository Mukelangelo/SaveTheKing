#include "Teleport.h"

void Teleport::handleCollision(GameObject& player)
{
	MovingObject* playerPtr = dynamic_cast<MovingObject*> (&player);
	m_dispatched = CollisionStatus::Good;
	if (typeid(player) != typeid(Mage) && !playerPtr->isTp())
	{
			m_dispatched = CollisionStatus::Teleport;
			playerPtr->teleported();
	}
}