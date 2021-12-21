#include "Board.h"

Board::Board()
{
	
}

void Board::drawMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		auto button = Button(sf::Vector2f(300, 80), m_texts[i], sf::Vector2f(800, 250 + i * 150));
		button.draw(window);
	}
}