#pragma once
#include "GameObject.h"

class StaticObject;
class Wall;
class Key;
class Throne;
class Fire;
class Teleport;
class Gate;
class Ogre;

class MovingObject : public GameObject
{
public:
	//using GameObject::GameObject;
	MovingObject(sf::Vector2f loc, const sf::Texture& texture);

	void movePlayer(sf::Time deltaTime);
	void setLocation(const sf::Vector2f& loc);
	virtual void setDirection(sf::Keyboard::Key key);
	
	virtual void handleCollision(GameObject& gameObject)=0 ;

	virtual void handleCollision(Wall& gameObject)=0;
	virtual void handleCollision(Throne& gameObject) = 0;
	virtual void handleCollision(Gate& gameObject) = 0;
	virtual void handleCollision(Fire& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Ogre& gameObject) = 0;
	virtual void handleCollision(Teleport& gameObject) = 0;

	
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