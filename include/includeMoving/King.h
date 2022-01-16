#pragma once

#include "includeMoving/MovingObject.h"

class King : public MovingObject
{
public:

	using MovingObject::MovingObject;
	virtual void handleCollision(GameObject& gameObject) override;
	

protected:
	virtual void DirectionImg(int dir) override;
};