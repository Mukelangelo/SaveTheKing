#pragma once

#include "Resources.h"
#include <vector>
#include <fstream>
#include <memory>
#include <stdlib.h> 
#include <time.h>
#include "macros.h"
#include "includeMoving/King.h"
#include "includeMoving/Mage.h"
#include "includeMoving/Warrior.h"
#include "includeMoving/Thief.h"
#include "includeStatic/Teleport.h"
#include "includeStatic/Key.h"
#include "includeStatic/Wall.h"
#include "includeStatic/Throne.h"
#include "includeStatic/Gate.h"
#include "includeStatic/Ogre.h"
#include "includeStatic/Fire.h"
#include "includeMoving/Gnome.h"
#include "includeStatic/TimeGift.h"
#include "includeStatic/BadTimeGift.h"
#include "includeStatic/RemoveGnomeGift.h"


class Board {
public:
	// default c-stor
	Board();
	Board(int width, int height, sf::Vector2f location);
	void draw(sf::RenderWindow& window,
			  const std::vector < std::unique_ptr <MovingObject >>& vect,
			  const std::vector < std::unique_ptr <StaticObject >>& tiles);
	void createObject(char c, const sf::Vector2f& vect, const sf::Texture& texture,
					  std::vector < std::unique_ptr <MovingObject >>& chararcters,
					  std::vector < std::unique_ptr <StaticObject >>& tiles);

	bool loadNextLevel(std::vector < std::unique_ptr <MovingObject >>& vect,
					   std::vector < std::unique_ptr <StaticObject >>& tiles);

	void resizeObjects(std::vector < std::unique_ptr <MovingObject >>& vect,
					   std::vector < std::unique_ptr <StaticObject >>& tiles);

	void setHalo(const std::unique_ptr < MovingObject >& player);

private:
	std::fstream m_file;

	// save the characters on the board
	std::vector< std::vector<char> > m_matrix;
	// draw and represent each character on the coard
	
	// location of the board on the screen
	sf::Vector2f m_location;

	// sizes of the board
	int m_rows, m_cols, m_height, m_width;

	// create all the tiles to present on screen
	void buildTiles(std::vector < std::unique_ptr <MovingObject >>& vect,
					std::vector < std::unique_ptr <StaticObject >>& tiles);

	sf::Sprite m_bg;
	sf::RectangleShape m_playerHalo;
};

