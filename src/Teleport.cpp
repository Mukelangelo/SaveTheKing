#include "Teleport.h"

/*void Teleport::handleCollision(GameObject& player)
{
	MovingObject* playerPtr = dynamic_cast<MovingObject*> (&player);
	//m_dispatched = CollisionStatus::Good;
	if (typeid(player) != typeid(Mage))
	{
		if (!playerPtr->isTp())
		{
			m_dispatched = CollisionStatus::Teleport;
			playerPtr->teleported();
			return;
		}
		else
		{
			m_dispatched = CollisionStatus::OnTeleport;
			return;
		}
			

	}
	m_dispatched = CollisionStatus::Good;
}
*/

void Teleport::handleCollision(King& gameObject) { m_dispatched = CollisionStatus::Teleport; }
void Teleport::handleCollision(Thief& gameObject) { m_dispatched = CollisionStatus::Teleport; }
void Teleport::handleCollision(Mage& gameObject) { m_dispatched = CollisionStatus::Teleport; }
void Teleport::handleCollision(Warrior& gameObject) { m_dispatched = CollisionStatus::Teleport; }
void Teleport::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Teleport; }