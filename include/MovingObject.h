#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;
	//MovingObject(const sf::Vector2f& loc);
	//MovingObject(int startR, int startC);

	void move(sf::Time deltaTime);
	void setLocation(const sf::Vector2f& loc);
	void setDirection(sf::Keyboard::Key key);
	virtual bool onSpecialTile();

	~MovingObject() = default;

protected:
	sf::Vector2f m_direction;
};