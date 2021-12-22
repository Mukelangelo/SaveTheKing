#include "Controller.h"

int stepCounter;
bool key, won;

Controller(std::string fileName)
	:m_board(fileName)
{
	init_vector();
}

void Controller::init_vector();
{
	m_character.push_back(std::make_unique<King>(sf::Vector2f()));
}

void Controller::run()
{

}