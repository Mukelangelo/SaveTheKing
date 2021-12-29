#include "Key.h"

void Key::handleCollision(GameObject& player)
{
	m_dispatched = false;
	//m_collided = true;
	if (typeid(player) == typeid(Thief))
		m_dispatched = true;
}