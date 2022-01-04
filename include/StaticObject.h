#pragma once

#include "GameObject.h"

class MovingObject;
class King;
class Mage;
class Thief;
class Warrior;
class Gnome;

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;

	//virtual void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(StaticObject& gameObject) {};
	virtual void handleCollision(King& gameObject)=0;
	virtual void handleCollision(Thief& gameObject)=0;
	virtual void handleCollision(Mage& gameObject)=0;
	virtual void handleCollision(Warrior& gameObject)=0;
	virtual void handleCollision(Gnome& gameObject)=0;

	CollisionStatus getDispatch();
	~StaticObject() = default;
	
protected:
	CollisionStatus m_dispatched ;
};