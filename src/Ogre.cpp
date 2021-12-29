#include "Ogre.h"

void Ogre::handleCollision(GameObject& player)
{
	m_dispatched = false;
	if (typeid(player) == typeid(Warrior))
	{
		m_dispatched == true;
	}
}