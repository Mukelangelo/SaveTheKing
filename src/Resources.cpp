#include "Resources.h"

Resources::Resources()
{
	loadTextures();
	loadBuffers();
	loadBackground();
	//setPauseScreen();
}

Resources::~Resources(){}

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}

void Resources::setPauseScreen()
{
	m_pauseScreen.setFillColor(sf::Color::Blue);
	m_pauseScreen.setPosition(sf::Vector2f(500, 500));
	m_pauseScreen.setSize(sf::Vector2f(500, 500));
	auto buttonSize = sf::Vector2f(30, 30);
	auto buttonPos = sf::Vector2f(550, 450);
	
	auto texture = sf::Texture();

	texture.loadFromFile("home-button.png");
	m_pauseButtons[Home].setTexture(&texture);

	texture.loadFromFile("restart-button.png");
	m_pauseButtons[Restart].setTexture(&texture);

	texture.loadFromFile("music-button.png");
	m_pauseButtons[Music].setTexture(&texture);

	m_pauseButtons[Music].setOutlineColor(sf::Color::Green);
	m_pauseButtons[Music].setOutlineThickness(3);
}


void Resources::loadTextures()
{
	for (int i = 0; i < NUM_OF_PICS; i++)
		m_textures[i].loadFromFile(objectTextures[i]);
}

sf::Texture* Resources::getTexture(char c)
{
	switch (c)
	{
	case 'K': return &m_textures[load_King];
	case 'M': return &m_textures[load_Mage];
	case 'W': return &m_textures[load_Warrior];
	case 'T': return &m_textures[load_Thief];
	case 'X': return &m_textures[load_Teleport];
	case 'F': return &m_textures[load_Key];
	case '=': return &m_textures[load_Wall];
	case '@': return &m_textures[load_Throne];
	case '#': return &m_textures[load_Gate];
	case '!': return &m_textures[load_Orge];
	case '*': return &m_textures[load_Fire];
	case '^': return &m_textures[load_Gnome];
	case '%': return &m_textures[load_Gift];
	}
}

sf::Texture* Resources::getTexture(int index)
{
	return &m_textures[index];
}

void Resources::loadBackground()
{
	auto loadPic = sf::Texture();
	loadPic.loadFromFile("gamebg.png");
	m_bg.push_back(loadPic);

	loadPic.loadFromFile("help.png");
	m_bg.push_back(loadPic);

	loadPic.loadFromFile("bg.png");
	m_bg.push_back(loadPic);
}

sf::Texture* Resources::getBackground(int index)
{
	return &m_bg[index];
}

void Resources::loadBuffers()
{
	for (int i = 0; i < NUM_OF_SOUNDS; i++)
	{
		if(!m_buffers[i].loadFromFile(soundBuffers[i]))
			return;
		m_sounds[i].setBuffer(m_buffers[i]);
		m_sounds[i].setVolume(50);
	}
}

void Resources::playSound(int index)
{
	m_sounds[index].play();
}

void Resources::drawPauseScreen(sf::RenderWindow& window)
{
	window.draw(m_pauseScreen);
	for (int i = 0; i < 3; i++)
	{
		window.draw(m_pauseButtons[i]);
	}	
}