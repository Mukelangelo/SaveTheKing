#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "macros.h"

class Resources
{
public:
	~Resources();
	static Resources& instance();

	sf::Texture* getTexture(char c);
	sf::Texture* getBackground();

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	void loadTextures();
	void loadBackground();

	sf::Texture m_textures[NUM_OF_PICS];
	sf::Texture m_bg;

	const std::string objectTextures[NUM_OF_PICS] = { "king.png", "mage.png", "warrior.png", "thief.png",
													"wall.png", "throne.png", "fire.png", "ogre.png",
													"teleport.png", "gate.png", "key.png", "gnome.png", "thiefKey.png", "gift.png" };
};