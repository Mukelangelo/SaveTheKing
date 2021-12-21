#pragma once

#include "Board.h"

class Window
{
public:
	Window();
	void run();
	void draw();

private:
	sf::RenderWindow m_window;
	Board m_board;

	sf::String m_texts[3] = { "Start game", "Help", "Exit" };
	Button m_buttons[3];
};