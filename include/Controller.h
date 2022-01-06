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
class Controller {
public:
	// default c-stor
	Controller();
	// run the game
	void run(sf::RenderWindow& window);

private:
	void setHalo();
	void eraseObject(StaticObject& staticObj);
	sf::Texture m_textures[NUM_OF_PICS];
	std::vector< std::unique_ptr <MovingObject > > m_character;
	std::vector< std::unique_ptr <StaticObject > > m_tiles;
	// vector of pointers to all moveable characters.
	Board m_board;
	void loadTextures();
	void switchCharacter();
	bool movementManger(int currChar, sf::Time& deltaTime, sf::Clock& clock);
	bool manageCollisions(int charIndex);
	bool locationAllowed(MovingObject& shape);
	void manageGifts(Gift& gift);
	int m_currChar;
	bool m_won = false;
	void findGnome();

	std::vector< sf::Vector2f > m_teleport;
	sf::Vector2f locateTeleport(const StaticObject& teleport);
	void readTeleports();
	void clearLastLevel();

	std::vector< int > m_gnomes;
	std::vector< sf::Clock > m_clocks;
	sf::RectangleShape m_playerHalo;
	Caption m_caption;
	sf::Font m_font;
};

