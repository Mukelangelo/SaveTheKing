#pragma once
#include "includeStatic/Gift.h"

class RemoveGnomeGift : public Gift
{
public:
	using Gift::Gift;
	//~RemoveGnomeGift();
	using Gift::handleCollision;
	
protected:
	void setType() override;
};
