#pragma once

#include "StaticObject.h"
#include "MovingObject.h"
#include <vector>
#include <iostream>

class Board {
public:
	// default c-stor
	Board();
	Board(std::string fileName, sf::Vector2f location);
	void drawBoard(sf::RenderWindow& window);

private:
	sf::Vector2f m_location;
	std::vector < std::vector < char >> m_matrix;

	//sf::Sprite charToSprite(char c);
};