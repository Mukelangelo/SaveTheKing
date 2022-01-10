#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class Button
{
public:
	Button();
	Button(const sf::Vector2f& size, sf::String text, const sf::Vector2f& pos);
	bool handleClick(const sf::Vector2f& location);
	void draw(sf::RenderWindow& window);
	// change the text on the button
	void setString(sf::String text);
	// get the written text on the button
	sf::String getString() const;
	// set color to the button
	void setColor(sf::Color color);
	void setColor();
	sf::FloatRect getGlobalBounds() const;

private:
	sf::RectangleShape m_button;
	sf::Color m_color;
	sf::String m_text;
	sf::ConvexShape m_spare;
	sf::Text m_buttonText;

	void initButton();
};