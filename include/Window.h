#pragma once

#include "Board.h"
#include "macros.h"

class Window
{
public:
	Window();
	void run();
	void draw();

private:
	sf::RenderWindow m_window;
	Board m_board;
	void handleButtons(const sf::Vector2f& location, bool& help_opened);
	void open_help();
	sf::String m_texts[MENU_BUTTONS] = { "Start game", "Help", "Exit" };
	Button m_buttons[MENU_BUTTONS];
	bool help_opened = false;
	int m_lastIndex = 0 ; // last button pressed
};