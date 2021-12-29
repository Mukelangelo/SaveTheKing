#include "Ogre.h"
#include "Key.h"

void Ogre::handleCollision(GameObject& player)
{
	m_dispatched = CollisionStatus::Good;
	if (typeid(player) != typeid(Warrior))
		m_dispatched = CollisionStatus::Not_Valid;
	else if (typeid(player) == typeid(Warrior))
		m_dispatched = CollisionStatus::Destroy;
}