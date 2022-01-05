#include "Gift.h"

void Gift::handleCollision(King& gameObject) { m_dispatched = CollisionStatus::Gift; }
void Gift::handleCollision(Thief& gameObject) { m_dispatched = CollisionStatus::Gift; }
void Gift::handleCollision(Mage& gameObject) { m_dispatched = CollisionStatus::Gift; }
void Gift::handleCollision(Warrior& gameObject) { m_dispatched = CollisionStatus::Gift; }
void Gift::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Good; }
