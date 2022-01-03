#include "Gate.h"

void Gate::handleCollision(GameObject& player)
{
	m_dispatched = CollisionStatus::Good;
	if (typeid(player) != typeid(Thief))
		m_dispatched = CollisionStatus::Not_Valid;
	else if (typeid(player) == typeid(Thief))
	{
		Thief* thiefptr = dynamic_cast<Thief*> (&player);
		if(!thiefptr->getKey())
			m_dispatched = CollisionStatus::Not_Valid;
		else
		{
			thiefptr->setKey(false);
			m_dispatched = CollisionStatus::Destroy;
		}	
	}
		

}
