#include "Resources.h"

Resources::Resources()
{
	loadTextures();
	loadBuffers();
	loadBackground();
}

Resources::~Resources(){}

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
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
	}
	
}

void Resources::playSound(int index)
{
	m_sounds[index].play();
}
