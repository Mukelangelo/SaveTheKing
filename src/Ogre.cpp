#include "Ogre.h"
#include "Key.h"

void Ogre::handleCollision(GameObject& player)
{
	m_dispatched = false;
	if (typeid(player) == typeid(Warrior))
	{
		
		m_dispatched = true;
	}
}