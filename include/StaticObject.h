#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	virtual void handleCollision(GameObject& player) override;
	
protected:
};