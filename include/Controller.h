#pragma once

#include "Board.h"
#include <cmath>
#include <ctime>


/*
List of missions :
	check collisions with other objects
	program gnome
*/
class Controller {
public:
	// default c-stor
	Controller();
	// run the game
	void run(sf::RenderWindow& window);
	~Controller();

private:
	void eraseObject(StaticObject& staticObj);
	void ChangeTile(StaticObject& staticObj);
	sf::Texture m_textures[NUM_OF_PICS];
	std::vector< std::unique_ptr <MovingObject > > m_character;
	std::vector< std::unique_ptr <StaticObject > > m_tiles;
	// vector of pointers to all moveable characters.
	Board m_board;
	void loadTextures();
	void switchCharacter();
	bool ManageCollisions(sf::Time& , sf::Clock&);
	int m_currChar;


};

