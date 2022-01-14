#pragma once
#include <string>
#include "macros.h"
#include "Resources.h"

class Caption
{
public:
	Caption();
	~Caption();

	void updateTime(float timeToAdd); // add amount of time to the timer
	void updateLevel(); // increase the level

	int getLvl() const; // get current level
	float getTime() const; //get current time left
	void resetTime(); // reset the timer to 0
	void draw(sf::RenderWindow&); 

	// print an end messege ( next level / lose / victory)
	void printMessege(const sf::String text, sf::RenderWindow& window);

private:

	// set the text settings and set the position based on i
	void setText(sf::Text& text , int i );

	sf::Clock m_Timer;
	float m_stageTime;
	int m_level;

	sf::Text m_stageTimeText;
	sf::Text m_levelText;

};