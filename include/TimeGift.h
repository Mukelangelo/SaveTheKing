#pragma once
#include "Gift.h"

class TimeGift : public Gift
{
public:
	using Gift::Gift;
	//~TimeGift();

	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Gnome& gameObject) override;

};