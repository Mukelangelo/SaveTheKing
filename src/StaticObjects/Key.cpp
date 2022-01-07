#include "includeStatic/Key.h"


void Key::handleCollision(Thief& gameObject)
{
	Thief* thiefptr = dynamic_cast<Thief*> (&gameObject);
	if (!thiefptr->getKey())
	{
		gameObject.handleCollision(*this);
		m_dispatched = CollisionStatus::Destroy;
	}
}

void Key::handleCollision(King& gameObject) { m_dispatched = CollisionStatus::Good; }
void Key::handleCollision(Mage& gameObject) { m_dispatched = CollisionStatus::Good; }
void Key::handleCollision(Warrior& gameObject) { m_dispatched = CollisionStatus::Good; }
void Key::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Good; }