#include "Throne.h"

void Throne::handleCollision(GameObject& player)
{
	m_dispatched = CollisionStatus::Good;
	if (typeid(player) != typeid(King))
		m_dispatched = CollisionStatus::Not_Valid;
	else if (typeid(player) == typeid(King))
		m_dispatched = CollisionStatus::Won;
}

