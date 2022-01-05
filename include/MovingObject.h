#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	//using GameObject::GameObject;
	MovingObject(sf::Vector2f loc, const sf::Texture& texture);

	void movePlayer(sf::Time deltaTime);
	void setLocation(const sf::Vector2f& loc);
	virtual void setDirection(sf::Keyboard::Key key);
	
	virtual void handleCollision(GameObject& gameObject) override {};
	virtual void handleCollision(Wall& gameObject) override {};
	virtual void handleCollision(Throne& gameObject) override {};
	virtual void handleCollision(Gate& gameObject) override {};
	virtual void handleCollision(Fire& gameObject) override {};
	virtual void handleCollision(Key& gameObject) override {};
	virtual void handleCollision(Ogre& gameObject) override {};
	virtual void handleCollision(Teleport& gameObject) override {};
	virtual void handleCollision(King& gameObject) override {};
	virtual void handleCollision(Thief& gameObject) override {};
	virtual void handleCollision(Mage& gameObject) override {};
	virtual void handleCollision(Warrior& gameObject) override {};
	virtual void handleCollision(Gnome& gameObject) override {};
	
	void setLastLoc(sf::Vector2f loc);
	sf::Vector2f getLastLoc();

	void teleported();
	bool isTp();
	~MovingObject() = default;

protected:
	sf::Vector2f m_direction;
	sf::Vector2f m_lastLoc;
	bool m_onTP = false;
	float m_speedPerSecond;
};