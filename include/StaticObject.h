#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;

	CollisionStatus getDispatch();
	~StaticObject() = default;

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

	
protected:
	CollisionStatus m_dispatched ;
};