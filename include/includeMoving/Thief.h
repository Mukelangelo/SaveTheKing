#pragma once

#include "includeMoving/MovingObject.h"

class Thief : public MovingObject
{
public:
	Thief(sf::Vector2f loc, const sf::Texture& texture);
	virtual void handleCollision(GameObject& gameObject) override;

	bool getKey();
	void setKey(bool status);

	virtual void handleCollision(Gate& gameObject) override;
	virtual void handleCollision(Key& gameObject) override;

protected:
	bool m_key = false;
};