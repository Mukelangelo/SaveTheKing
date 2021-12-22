#include "Controller.h"

int stepCounter;
bool key, won;

Controller::Controller(std::string fileName)
	:m_board(fileName)
{
	loadTextures();
	init_vector();
}

void Controller::initVector()
{
	m_character.push_back(std::make_unique<King>());
}

void Controller::run()
{
	
}

void Controller::loadTextures()
{
	for (int i = 0; i < NUM_OF_PICS; i++)
		m_textures[i].loadFromFile(objectTextures[i]);
}
