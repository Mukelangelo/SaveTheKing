#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;

	void movePlayer(sf::Time deltaTime);
	void setLocation(const sf::Vector2f& loc);
	void setDirection(sf::Keyboard::Key key);
	// should be in GameObject , here only for the beta version
	virtual void handleCollision(MovingObject& player) = 0;
	//virtual bool onSpecialTile();

	~MovingObject() = default;

protected:
	sf::Vector2f m_direction;
};