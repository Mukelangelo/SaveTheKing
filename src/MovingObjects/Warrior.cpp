#include "includeMoving/Warrior.h"

Warrior::Warrior(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}

void Warrior::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

void Warrior::DirectionImg(int dir)
{
	switch (dir)
	{
	case Up:
		m_sprite.setTexture(*Resources::instance().getTexture(load_WarriorUp));
		break;

	case Down:
		m_sprite.setTexture(*Resources::instance().getTexture(load_WarriorDown));
		break;

	case Left:
		m_sprite.setTexture(*Resources::instance().getTexture(load_Warrior));
		m_sprite.scale(-1, 1);
		break;
	case Right:
		m_sprite.setTexture(*Resources::instance().getTexture(load_Warrior));
		break;
	default:
		break;
	}
}