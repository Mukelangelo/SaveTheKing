#include "Teleport.h"

void Teleport::handleCollision(King& gameObject) { m_dispatched = CollisionStatus::Teleport; }
void Teleport::handleCollision(Thief& gameObject) { m_dispatched = CollisionStatus::Teleport; }
void Teleport::handleCollision(Mage& gameObject) { m_dispatched = CollisionStatus::Good; }
void Teleport::handleCollision(Warrior& gameObject) { m_dispatched = CollisionStatus::Teleport;	}
void Teleport::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Teleport; }