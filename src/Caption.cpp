#include "Caption.h"

Caption::Caption() : m_level(0), m_stageTime(10)
{

	m_font.loadFromFile("C:/Windows/Fonts/Comic.ttf");


	setText(m_stageTimeText, 0);
	setText(m_levelText, 1);
}

void Caption::setText(sf::Text& text , int i)
{
	text.setFont(m_font);
	text.setCharacterSize(40);
	text.setPosition( 300 * i + 50 , WINDOW_HEIGHT - BAR_SIZE + 10);
	text.setColor(sf::Color::Green);
	text.setOutlineColor(sf::Color::Blue);
	text.setOutlineThickness(3);
}

Caption::~Caption()
{
}

void Caption::updateTime(float time)
{

	m_stageTime += time;
	m_stageTime -= m_Timer.getElapsedTime().asSeconds();

	m_stageTimeText.setString("Time left: " + std::to_string((int)this->m_stageTime));


	m_Timer.restart();

}

void Caption::updateLevel()
{
	this->m_level++;
	this->m_levelText.setString("Level:" + std::to_string(this->m_level));
	this->m_Timer.restart();

}

int Caption::getLvl() const
{
	return this->m_level;
}

float Caption::getTime() const
{
	return m_stageTime;
}

void Caption::resetLvl()
{
	m_Timer.restart();
}

void Caption::resetTime(int time)
{
	m_stageTime = time;
}

void Caption::draw(sf::RenderWindow& window)
{
	updateTime(0);
	window.draw(this->m_levelText);
	window.draw(this->m_stageTimeText);

}

void Caption::resetLevelNum()
{
	m_level = 0;
}