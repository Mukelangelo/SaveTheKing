#pragma once

#include "MovingObject.h"
#include <Throne.h>

class King : public MovingObject
{
public:
	King(sf::Vector2f loc, const sf::Texture& texture);
	//virtual bool onSpecialTile() ; // on Throne
	//void handleCollision(GameObject& gameObject) override;
	virtual void handleCollision(MovingObject& player) override ;

private:
	//sf::Vector2f m_throne; // do we really need it here?
	bool m_win = false;
};