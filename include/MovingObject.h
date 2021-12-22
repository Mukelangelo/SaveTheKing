#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;

	void movePlayer(sf::Time deltaTime);
	void setLocation(const sf::Vector2f& loc);
	void setDirection(sf::Keyboard::Key key);
	virtual bool onSpecialTile() = 0;

	~MovingObject() = default;

protected:
	sf::Vector2f m_direction;
};