#include "Gnome.h"

Gnome::Gnome(sf::Vector2f loc, const sf::Texture& texture)
	:MovingObject(loc, texture)
{}

void Gnome::handleCollision(MovingObject& player)
{
	if (&player == this) return;

}