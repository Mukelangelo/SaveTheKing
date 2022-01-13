#include "Caption.h"

Caption::Caption() : m_level(0), m_stageTime(0)
{
	setText(m_stageTimeText, 0);
	setText(m_levelText, 1);
}

void Caption::setText(sf::Text& text , int i)
{
	text.setFont(*Resources::instance().getFont());
	text.setCharacterSize(40);
	text.setPosition( 300 * i + 50 , WINDOW_HEIGHT - BAR_SIZE + 10);
	text.setColor(sf::Color::Green);
	text.setOutlineColor(sf::Color::Blue);
	text.setOutlineThickness(3);
}

Caption::~Caption() {}

void Caption::updateTime(float time)
{

	m_stageTime += time;
	m_stageTime -= m_Timer.getElapsedTime().asSeconds();

	m_stageTimeText.setString("Time left: " + std::to_string((int)m_stageTime));


	m_Timer.restart();

}

void Caption::updateLevel()
{
	m_level++;
	m_levelText.setString("Level:" + std::to_string(m_level));
	m_Timer.restart();

}

int Caption::getLvl() const
{
	return this->m_level;
}

float Caption::getTime() const
{
	return m_stageTime;
}


void Caption::resetTime()
{
	m_stageTime = 0;
}

void Caption::draw(sf::RenderWindow& window)
{
	updateTime(0);
	window.draw(m_levelText);
	window.draw(m_stageTimeText);
}
