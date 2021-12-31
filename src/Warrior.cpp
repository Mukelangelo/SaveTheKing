#include "Warrior.h"

Warrior::Warrior(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}

void Warrior::handleCollision(MovingObject& player)
{
	if (&player == this) return;
	
}
