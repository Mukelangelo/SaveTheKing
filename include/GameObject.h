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

	virtual void handleCollision(GameObject& ) = 0;
	virtual void handleCollision(Wall& ) = 0;
	virtual void handleCollision(Throne& ) = 0;
	virtual void handleCollision(Gate& ) = 0;
	virtual void handleCollision(Fire& ) = 0;
	virtual void handleCollision(Key& ) = 0;
	virtual void handleCollision(Ogre& ) = 0;
	virtual void handleCollision(Teleport& ) = 0;
	virtual void handleCollision(King& ) = 0;
	virtual void handleCollision(Thief& ) = 0;
	virtual void handleCollision(Mage& ) = 0;
	virtual void handleCollision(Warrior& ) = 0;
	virtual void handleCollision(Gnome& ) = 0;

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