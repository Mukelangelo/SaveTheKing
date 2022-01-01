#pragma once

#include <vector>
#include <fstream>
#include <memory>
#include "macros.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Teleport.h"
#include "Key.h"
#include "Wall.h"
#include "Throne.h"
#include "Gate.h"
#include "Ogre.h"
#include "Fire.h"
#include "Gnome.h"

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
		std::vector < std::unique_ptr <MovingObject >>& vect,
		std::vector < std::unique_ptr <StaticObject >>& tiles,
		sf::Texture textures[]);
	void draw(sf::RenderWindow& window);
	sf::Texture& getTexture(char c);
	void createObject(char c, const sf::Vector2f& vect, const sf::Texture& texture);

private:
	std::fstream m_file;
	void resizeObjects();
	// save the characters on the board
	std::vector< std::vector<char> > m_matrix;
	// draw and represent each character on the coard
	
	// location of the board on the screen
	sf::Vector2f m_location;

	// sizes of the board
	int m_rows, m_cols, m_height, m_width;

	// create all the tiles to present on screen
	void buildTiles();

	std::vector< std::unique_ptr <MovingObject > >* m_character;
	std::vector< std::unique_ptr <StaticObject > >* m_tiles;
	sf::Texture* m_textures;

	sf::Sprite m_bg;
	sf::Texture m_texture;
};