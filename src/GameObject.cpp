#include "GameObject.h"

GameObject::GameObject(sf::Vector2f loc, const sf::Texture& texture)
	: m_location(loc), m_sprite(sf::Sprite(texture))
{
	m_sprite.setPosition(m_location);
	m_sprite.setScale(sf::Vector2f(0.8, 0.8));
}

void GameObject::draw(sf::RenderWindow& window)
{ 
	window.draw(m_sprite);
}

sf::Vector2f GameObject::getLocation() const
{
	return m_location;
}