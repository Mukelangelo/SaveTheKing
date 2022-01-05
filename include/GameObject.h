#pragma once

#include "macros.h"

class King;
class Mage;
class Thief;
class Warrior;
class Gnome;
class Wall;
class Key;
class Throne;
class Fire;
class Teleport;
class Gate;
class Ogre;


class GameObject
{
public:
	GameObject(sf::Vector2f loc, const sf::Texture& texture); 
	bool checkCollision(const GameObject& other);

	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(Throne& gameObject) = 0;
	virtual void handleCollision(Gate& gameObject) = 0;
	virtual void handleCollision(Fire& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Ogre& gameObject) = 0;
	virtual void handleCollision(Teleport& gameObject) = 0;
	virtual void handleCollision(King& gameObject) = 0;
	virtual void handleCollision(Thief& gameObject) = 0;
	virtual void handleCollision(Mage& gameObject) = 0;
	virtual void handleCollision(Warrior& gameObject) = 0;
	virtual void handleCollision(Gnome& gameObject) = 0;

	void draw(sf::RenderWindow& window);
	sf::Vector2f getLocation() const;
	sf::Sprite getSprite() const;
	void setSpriteTexture(sf::Texture s) ;
	void setSpriteScale(double ScaleX, double ScaleY);
	virtual ~GameObject() = default;

protected:
	sf::Vector2f m_location;
	sf::Sprite m_sprite;
};