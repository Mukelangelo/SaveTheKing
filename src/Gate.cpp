#include "Gate.h"

void Gate::handleCollision(GameObject& player)
{
	m_dispatched = false;
	//m_collided = true;
	if (typeid(player) == typeid(Thief))
	{
		m_dispatched = true;
	}

}
