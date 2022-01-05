#include "BadTimeGift.h"

void BadTimeGift::handleCollision(King& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::TimeDec;
}

void BadTimeGift::handleCollision(Thief& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::TimeDec;
}

void BadTimeGift::handleCollision(Mage& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::TimeDec;
}

void BadTimeGift::handleCollision(Warrior& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::TimeDec;
}

void BadTimeGift::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Good; }