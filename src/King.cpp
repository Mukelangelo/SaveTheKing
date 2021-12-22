
#include "King.h"

King::King(sf::vector2f throneLoc)
	:m_throne(throneLoc);
{
	MovingObject(load_King , sf::Vector2f(1,1));
}


virtual bool King::onSpecialTile() override
{
	if (m_location == m_throne)
		return true;
}