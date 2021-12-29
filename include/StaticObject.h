#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	virtual void handleCollision(GameObject& player) override;
	bool isDispatch();
	
protected:
	bool m_dispatched ;
	//bool m_collided;
};