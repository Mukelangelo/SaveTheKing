
#include "RemoveGnomeGift.h"


void RemoveGnomeGift::handleCollision(King& gameObject) 
{
	m_dispatched = CollisionStatus::Gift; 
	m_giftType = GiftTypes::RemGnomes;
}

void RemoveGnomeGift::handleCollision(Thief& gameObject) 
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::RemGnomes;
}

void RemoveGnomeGift::handleCollision(Mage& gameObject) 
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::RemGnomes;
}

void RemoveGnomeGift::handleCollision(Warrior& gameObject)
{
	m_dispatched = CollisionStatus::Gift;
	m_giftType = GiftTypes::RemGnomes;
}

void RemoveGnomeGift::handleCollision(Gnome& gameObject) { m_dispatched = CollisionStatus::Good; }