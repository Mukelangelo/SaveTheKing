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
	
	virtual void handleCollision(GameObject& ) override {};
	virtual void handleCollision(Wall& ) override {};
	virtual void handleCollision(Throne& ) override {};
	virtual void handleCollision(Gate& ) override {};
	virtual void handleCollision(Fire& ) override {};
	virtual void handleCollision(Key& ) override {};
	virtual void handleCollision(Ogre& ) override {};
	virtual void handleCollision(Teleport& ) override {};
	virtual void handleCollision(King& ) override {};
	virtual void handleCollision(Thief& ) override {};
	virtual void handleCollision(Mage& ) override {};
	virtual void handleCollision(Warrior& ) override {};
	virtual void handleCollision(Gnome& ) override {};
	
	void setLastLoc(sf::Vector2f loc);
	sf::Vector2f getLastLoc();

	void teleported();
	bool isTp();
	virtual ~MovingObject() = default;

protected:
	sf::Vector2f m_direction;
	sf::Vector2f m_lastLoc;
	bool m_onTP = false;
	float m_speedPerSecond;

};