#pragma once
#include "Gift.h"

class TimeGift : public Gift
{
public:
	using Gift::Gift;
	//~TimeGift();
	using Gift::handleCollision;
	

protected:
	void setType() override;

};