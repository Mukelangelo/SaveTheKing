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
	sf::Texture m_textures[NUM_OF_PICS];
	std::vector< std::unique_ptr <MovingObject > > m_character;
	std::vector< std::unique_ptr <StaticObject > > m_tiles;
	// vector of pointers to all moveable characters.
	Board m_board;
	void loadTextures();
	void switchCharacter();
	bool manageCollisions(int charIndex , sf::Time& , sf::Clock&);
	bool locationAllowed(MovingObject& shape);
	int m_currChar;
	bool m_won = false;
	void findGnome();

	std::vector< sf::Vector2f > m_teleport;
	sf::Vector2f locateTeleport(const StaticObject& teleport);
	void readTeleports();

	std::vector< int > m_gnomes;
};

