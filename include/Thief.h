#pragma once

#include "MovingObject.h"


class Thief : public MovingObject
{
public:
	Thief(sf::Vector2f loc, const sf::Texture& texture);
	bool getKey();
	void setKey(bool status);
	virtual void handleCollision(MovingObject& player) override;

protected:
	//bool m_key;
};