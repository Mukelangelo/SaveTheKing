#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	virtual void handleCollision(GameObject& player) =0;
	bool isDispatch();
	
protected:
	bool m_dispatched ;
	//bool m_collided;
};