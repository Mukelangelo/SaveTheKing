#pragma once

#include "Board.h"
#include <cmath>
#include <ctime>
#include "Caption.h"

/*
List of missions :
	check collisions with other objects
	program gnome
*/

struct TeleportInfo {
	TeleportInfo(sf::Vector2f loc)
	{
		m_loc = loc;
		m_isUsed = false;
	}
	sf::Vector2f m_loc;
	bool m_isUsed;
};

class Controller {
public:
	// default c-stor
	Controller();
	// run the game
	void run(sf::RenderWindow& window);

private:
	
	void handleVictory(sf::RenderWindow& window);
	void eraseGnomes();
	void eraseObject(StaticObject& staticObj);
	std::vector< std::unique_ptr <MovingObject > > m_character;
	std::vector< std::unique_ptr <StaticObject > > m_tiles;
	// vector of pointers to all moveable characters.
	Board m_board;
	void switchCharacter();
	bool movementManger(int currChar, sf::Time& deltaTime, sf::Clock& clock);
	bool manageCollisions(int charIndex);
	bool locationAllowed(MovingObject& shape);
	void manageGifts(StaticObject& gift);
	bool PauseMenu(sf::RenderWindow& window);
	void printMessege(const sf::String text , sf::RenderWindow& window);

	int m_currChar;
	bool m_won = false;
	void findGnome();

	std::vector< TeleportInfo > m_teleport;
	sf::Vector2f locateTeleport(const StaticObject& teleport);
	void readTeleports();
	void clearLastLevel();

	std::vector< int > m_gnomes;
	std::vector< sf::Clock > m_clocks;
	Caption m_caption;
	int m_numOfGnomes;
};

