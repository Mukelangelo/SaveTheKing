#include "Key.h"

void Key::handleCollision(GameObject& player)
{
	m_dispatched = CollisionStatus::Good;
	if (typeid(player) == typeid(Thief))
	{
		Thief* thiefptr = dynamic_cast<Thief*> (&player);
		if (!thiefptr->getKey())
		{
			thiefptr->setKey(true);
			m_dispatched = CollisionStatus::Destroy;
		}
	}
		
}