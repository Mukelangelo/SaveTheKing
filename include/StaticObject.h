#pragma once

#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	void handleCollision(GameObject& gameObject) override;
protected:
};