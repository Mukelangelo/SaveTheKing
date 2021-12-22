#pragma once

#include "Board.h"
#include "macros.h"

class Menu
{
public:
	Menu();
	void run();
	void draw();

private:
	sf::RenderWindow m_window;
	Board m_board;
	void handleButtons(const sf::Vector2f& location);
	void handleHover(const sf::Vector2f& location);
	sf::String m_texts[MENU_BUTTONS] = { "Start game", "Help", "Exit" };
	Button m_buttons[MENU_BUTTONS];
	bool m_need_help;
	bool m_gameStart;
	int m_lastHover;
	sf::RectangleShape m_help_bar;
};