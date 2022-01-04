#pragma once

#include "MovingObject.h"

class Thief : public MovingObject
{
public:
	Thief(sf::Vector2f loc, const sf::Texture& texture);
	virtual void handleCollision(GameObject& gameObject) override;

	bool getKey();
	void setKey(bool status);

	virtual void handleCollision(Gate& gameObject) override;
	virtual void handleCollision(Key& gameObject) override;
	virtual void handleCollision(Wall& gameObject) override;
	virtual void handleCollision(Throne& gameObject) override;
	virtual void handleCollision(Fire& gameObject) override;
	virtual void handleCollision(Ogre& gameObject) override;
	virtual void handleCollision(Teleport& gameObject) override;

	

private:
	bool m_key;
};