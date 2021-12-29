#include "Fire.h"

void Fire::handleCollision(GameObject& player)
{
	m_dispatched = false;
	//m_collided = true;
	if (typeid(player) == typeid(Mage))
		m_dispatched == true;

}