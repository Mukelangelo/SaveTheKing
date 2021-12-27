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
	Controller(sf::RenderWindow& window);
	// run the game
	void run();
	~Controller();

private:

	sf::RenderWindow* m_window;
	sf::Texture m_textures[NUM_OF_PICS];
	std::vector< std::unique_ptr <MovingObject > > m_character;
	// vector of pointers to all moveable characters.
	Board m_board;
	void loadTextures();
	void switchCharacter();
	bool handleCollisions();
	int m_currChar;

};

