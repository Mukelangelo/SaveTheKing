#pragma once
#include <string>
#include "macros.h"

class Caption
{
public:
	Caption();
	~Caption();

	void updateTime(float);
	void updateLevel();

	int getLvl() const;
	float getTime() const;
	void resetLvl();
	void resetTime();
	void draw(sf::RenderWindow&);
	void resetLevelNum();

private:

	void setText(sf::Text& text , int i);

	sf::Clock m_Timer;
	float m_stageTime;
	int m_level;
	int m_score;
	bool m_timelessLevel;

	sf::Text m_stageTimeText;
	sf::Text m_levelText;
	sf::Font m_font;

};

