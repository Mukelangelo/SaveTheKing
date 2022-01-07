#include "includeStatic/Gift.h"

GiftTypes Gift::getType()
{
	return m_giftType;
}

void Gift::setType()
{
	m_giftType = GiftTypes::TimeDec;
}
void Gift::handleCollision(King& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	setType();
}

void Gift::handleCollision(Thief& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	setType();
}

void Gift::handleCollision(Mage& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	setType();
}

void Gift::handleCollision(Warrior& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	setType();
}

void Gift::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Good; }
