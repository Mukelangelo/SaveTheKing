#pragma once

#include "Board.h"

class Window
{
public:
	Window();
	void run();

private:
	sf::RenderWindow m_window;
	Board m_board;
	
};