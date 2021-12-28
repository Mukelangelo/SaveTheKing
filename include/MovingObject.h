#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	//using GameObject::GameObject;
	MovingObject(sf::Vector2f loc, const sf::Texture& texture);

	void movePlayer(sf::Time deltaTime);
	void setLocation(const sf::Vector2f& loc);
	void setDirection(sf::Keyboard::Key key);
	// should be in GameObject , here only for the beta version
	virtual void handleCollision(MovingObject& player) = 0;
	void handleCollision(GameObject& gameObject) override;
	//virtual bool onSpecialTile();
	sf::Vector2f getDirection();
	void setLastLoc(sf::Vector2f loc);
	sf::Vector2f getLastLoc();
	~MovingObject() = default;

protected:
	sf::Vector2f m_direction;
	sf::Vector2f m_lastLoc;
};