#pragma once

#include "Board.h"
#include <cmath>
#include <ctime>
#include "Caption.h"

// details on a teleport tile
struct TeleportInfo {
	TeleportInfo(sf::Vector2f loc)
	{
		m_loc = loc; 
		m_isUsed = false; 
	}
	sf::Vector2f m_loc; // the location of the teleport
	bool m_isUsed; // if a character is standing on the teleport
};

class Controller {
public:
	// default c-stor
	Controller();
	// run the game
	void run(sf::RenderWindow& window);

private:
	
	void restartLvl();
	bool eventsHandler(sf::Event& event , sf::RenderWindow& window);
	void handleVictory(sf::RenderWindow& window);

	// erase objects from matching arrays
	void eraseGnomes();
	void eraseObject(StaticObject& staticObj);

	std::vector< std::unique_ptr <MovingObject > > m_character;
	std::vector< std::unique_ptr <StaticObject > > m_tiles;
	// vector of pointers to all moveable characters.
	

	void switchCharacter();

	// move the character m_character[currChar] using the deltaTime and clock.
	bool movementManger(int currChar, sf::Time& deltaTime, sf::Clock& clock);

	// check collisions on m_character[charIndex] with all other objects.
	bool manageCollisions(int charIndex);

	// check if the location is out of board bounds
	bool locationAllowed(const MovingObject& shape);

	void manageGifts(StaticObject& gift); // handle the gifts the player collected

	bool PauseMenu(sf::RenderWindow& window);
	sf::Vector2f locateTeleport(const StaticObject& teleport);

	Board m_board;
	int m_currChar;
	bool m_won = false;
	void findGnome();

	std::vector< TeleportInfo > m_teleport;

	void readTeleports(); 
	void clearLastLevel();

	std::vector< int > m_gnomes;
	std::vector< sf::Clock > m_clocks;
	Caption m_caption;
	int m_numOfGnomes;
};

