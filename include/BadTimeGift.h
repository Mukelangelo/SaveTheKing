#pragma once
#include "Gift.h"

class BadTimeGift : public Gift
{
public:
	using Gift::Gift;
	//~BadTimeGift();
	using Gift::handleCollision;
	//virtual void handleContoller(Controller& controller) override;

protected:
	void setType() override;
};
