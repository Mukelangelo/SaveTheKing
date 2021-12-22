#pragma once
#include <vector>
#include <memory>

/*
List of missions : 
	create the window of the game 
	create board
*/
	class Controller {
public:
	// default c-stor
	Controller(std::string fileName);
	// run the game
	void init_vector();
	void run();
	void drawMenu(sf::RenderWindow& window);

private:
	
	std::vector< std::unique_ptr <MovingObject > > m_character; 
	// vector of pointers to all moveable characters.
	Board m_board;
};

