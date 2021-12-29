#include "Teleport.h"

void Teleport::handleCollision(GameObject& player)
{
	m_dispatched = false;
	if (typeid(player) == typeid(Mage))
		m_dispatched = true;
}