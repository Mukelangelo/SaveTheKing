#pragma once

#include "StaticObject.h"
#include "MovingObject.h"
#include <vector>
#include <iostream>

class Board {
public:
	// default c-stor
	Board();
	Board(int width, int height, sf::Vector2f location);
	Board(std::string fileName, sf::Vector2f location);
	void drawBoard(sf::RenderWindow& window);

private:
	sf::Vector2f m_location;
	int m_width, m_height, m_rows, m_cols;
	std::vector < std::vector < char >> m_matrix;
	sf::Texture m_textures[NUM_OF_PICS];
	std::vector< std::unique_ptr <MovingObject > > m_character;

	void loadTextures();
	void buildTiles();
	
	//sf::Sprite charToSprite(char c);
};