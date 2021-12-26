#pragma once

#include "macros.h"

class GameObject
{
public:
	GameObject(sf::Vector2f loc, const sf::Texture& texture); 
	void draw(sf::RenderWindow& window);
	sf::Vector2f getLocation() const;
	~GameObject() = default;

protected:
	sf::Vector2f m_location;
	sf::Sprite m_sprite;
};