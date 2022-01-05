#include "TimeGift.h"

void TimeGift::handleCollision(King& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::TimeAdd;
}

void TimeGift::handleCollision(Thief& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::TimeAdd;
}

void TimeGift::handleCollision(Mage& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::TimeAdd;
}

void TimeGift::handleCollision(Warrior& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::TimeAdd;
}

void TimeGift::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Good; }