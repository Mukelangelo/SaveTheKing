#pragma once

#include "StaticObject.h"

enum class GiftTypes{TimeAdd, RemGnomes};

class Gift : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual void handleCollision(GameObject& gameObject) override {};
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Gnome& gameObject) override;

	//GiftTypes getGift();

private:
	GiftTypes m_giftType;
};