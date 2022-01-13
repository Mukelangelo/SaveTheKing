#pragma once
#include <string>
#include "macros.h"
#include "Resources.h"

class Caption
{
public:
	Caption();
	~Caption();

	void updateTime(float);
	void updateLevel();

	int getLvl() const;
	float getTime() const;
	void resetTime();
	void draw(sf::RenderWindow&);

private:

	// set the text settings and set the position based on i
	void setText(sf::Text& text , int i );

	sf::Clock m_Timer;
	float m_stageTime;
	int m_level;

	sf::Text m_stageTimeText;
	sf::Text m_levelText;

};

