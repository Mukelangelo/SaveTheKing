#pragma once
#include "Gift.h"

class RemoveGnomeGift : public Gift
{
public:
	using Gift::Gift;
	//~RemoveGnomeGift();
	virtual void handleCollision(Mage& gameObject) override;
	virtual void handleCollision(King& gameObject) override;
	virtual void handleCollision(Thief& gameObject) override;
	virtual void handleCollision(Warrior& gameObject) override;
	virtual void handleCollision(Gnome& gameObject) override;
};
