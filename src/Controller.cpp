#include "Controller.h"

int stepCounter;
bool key, won;

Controller::Controller(sf::RenderWindow& window, std::string fileName);
	:m_board(fileName)
{
	m_window = window;
	run();
	//init_vector();
}

/*void Controller::initVector()
{
	m_character.push_back(std::make_unique<King>());
}
*/
void Controller::run()
{
	
}

void Controller::loadTextures()
{
	for (int i = 0; i < NUM_OF_STATIC; i++)
		m_textures[i].loadFromFile(staticObjectTextures[i]);
}