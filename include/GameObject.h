#pragma once

#include "macros.h"

class GameObject
{
public:
	GameObject(sf::Vector2f loc, const sf::Texture& texture); 
	bool checkCollision(const GameObject& other);

	virtual void handleCollision(GameObject& gameObject) = 0;

	void draw(sf::RenderWindow& window);
	sf::Vector2f getLocation() const;
	sf::Sprite getSprite() const;
	void setSpriteTexture(sf::Texture s) ;
	void setSpriteScale(double ScaleX, double ScaleY);
	~GameObject() = default;

protected:
	sf::Vector2f m_location;
	sf::Sprite m_sprite;
};