#pragma once

#include "StaticObject.h"

enum class GiftTypes{TimeAdd, RemGnomes , TimeDec};

class Gift : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual void handleCollision(GameObject& gameObject) override {};
	GiftTypes getType();

protected:
	GiftTypes m_giftType;
};