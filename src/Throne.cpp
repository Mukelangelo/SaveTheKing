#include "Throne.h"

void Throne::handleCollision(King& player)
{
	//m_dispatched = CollisionStatus::Good;
	//m_dispatched = CollisionStatus::Not_Valid;
	m_dispatched = CollisionStatus::Won;
}

//void Throne::handleCollision(King& gameObject) { m_dispatched = CollisionStatus::Not_Valid; }
void Throne::handleCollision(Thief& gameObject) { m_dispatched = CollisionStatus::Not_Valid; }
void Throne::handleCollision(Mage& gameObject) { m_dispatched = CollisionStatus::Not_Valid; }
void Throne::handleCollision(Warrior& gameObject) { m_dispatched = CollisionStatus::Not_Valid; }
void Throne::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Not_Valid; }
