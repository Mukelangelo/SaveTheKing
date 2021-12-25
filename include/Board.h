#pragma once

#include <vector>
#include <fstream>
#include "macros.h"
#include "MovingObject.h"

#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"

#include <memory>

/*
List of missions :
	read from file and creat ibjects in
	the right place on window
	add static objects
*/

class Board {
public:
	// default c-stor
	Board();
	Board(int width, int height, sf::Vector2f location,
		std::vector < std::unique_ptr <MovingObject >>& vect, sf::Texture textures[]);
	void draw(sf::RenderWindow& window);

private:
	std::fstream m_file;
	// save the characters on the board
	std::vector< std::vector<char> > m_matrix;
	// draw and represent each character on the coard
	std::vector < std::vector < sf::Sprite > > m_tiles;
	// location of the board on the screen
	sf::Vector2f m_location;
	// sizes of the board
	int m_rows, m_cols, m_height, m_width;

	// create all the tiles to present on screen
	void buildTiles();

	std::vector< std::unique_ptr <MovingObject > >* m_character;
	sf::Texture* m_textures;
};