#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	virtual void handleCollision(GameObject& player) =0;
	CollisionStatus getDispatch();
	
protected:
	CollisionStatus m_dispatched ;
	//bool m_collided;
};