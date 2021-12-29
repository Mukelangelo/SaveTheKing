#include "StaticObject.h"

void StaticObject::handleCollision(GameObject& player)
{
	m_dispatched = true;
}

bool StaticObject::isDispatch()
{
	return m_dispatched;
}