#pragma once

#include "includeStatic/StaticObject.h"

enum class GiftTypes{TimeAdd, RemGnomes , TimeDec};

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
	GiftTypes getType();

protected:
	virtual void setType();
	GiftTypes m_giftType; 
};