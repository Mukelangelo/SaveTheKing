#include "includeMoving/Thief.h"

Thief::Thief(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)//, m_key(false)
{}

void Thief::setKey(bool status)
{
	m_key = status;
}

bool Thief::getKey()
{
	return m_key;
}

void Thief::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this)
		return;

	gameObject.handleCollision(*this);
}

void Thief::handleCollision(Gate& gameObject)
{
	m_key = false;
	m_sprite.setTexture(*Resources::instance().getTexture(load_Thief));
}

void Thief::handleCollision(Key& gameObject)
{
	m_key = true;
	m_sprite.setTexture(*Resources::instance().getTexture(load_ThiefKey));
}

void Thief::DirectionImg(int dir)
{
	int index;
	(m_key) ? index = load_ThiefKey : index = load_Thief;
	m_sprite.setTexture(*Resources::instance().getTexture(index + dir));
}