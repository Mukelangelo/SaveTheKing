#include "includeStatic/Key.h"


void Key::handleCollision(Thief& player)
{
	if (!player.getKey())
	{
		player.handleCollision(*this);
		m_dispatched = CollisionStatus::Destroy;
	}
}

void Key::handleCollision(King& ) { m_dispatched = CollisionStatus::Not_Valid; }
void Key::handleCollision(Mage& ) { m_dispatched = CollisionStatus::Not_Valid; }
void Key::handleCollision(Warrior& ) { m_dispatched = CollisionStatus::Not_Valid; }
void Key::handleCollision(Gnome& ) { m_dispatched = CollisionStatus::Not_Valid; }