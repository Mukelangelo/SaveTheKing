#pragma once

#include "Button.h"
#include <vector>
#include <iostream>

class Board {
public:
	// default c-stor
	Board();
	Board(int width, int height, sf::Vector2f location);
	void drawMenu(sf::RenderWindow& window);

private:
	// all the pictures to load
	//sf::Texture m_textures[NUM_OF_PICTURES];
	// load all photos from memmory
	void loadTextures();

};