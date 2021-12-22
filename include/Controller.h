#pragma once
#include <vector>
#include <memory>
#include "MovingObject.h"
#include "StaticObject.h"
#include "Board.h"
#include "macros.h"

/*
List of missions : 
	create the window of the game 
	create board
*/
	class Controller {
public:
	// default c-stor
	Controller(); // sf::RenderWindow& window);
	// run the game
	void initVector();
	void run();
	//void drawMenu(sf::RenderWindow& window);

private:
	
	sf::RenderWindow m_window;
	sf::Texture m_textures[NUM_OF_PICS];
	std::vector< std::unique_ptr <MovingObject > > m_character; 
	// vector of pointers to all moveable characters.
	Board m_board;
	void loadTextures();
	
};

