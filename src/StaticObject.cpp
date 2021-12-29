#include "StaticObject.h"

/*void StaticObject::handleCollision(GameObject& player)
{
	//m_dispatched = true;
}
*/
CollisionStatus StaticObject::getDispatch()
{
	return m_dispatched;
}