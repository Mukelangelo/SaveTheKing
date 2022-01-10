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
	sf::Texture* getTexture(int i);
	sf::Texture* getBackground(int index);
	void drawPauseScreen(sf::RenderWindow& window);
	void playSound(int index);

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	sf::SoundBuffer m_buffers[NUM_OF_SOUNDS];
	sf::Sound m_sounds[NUM_OF_SOUNDS];

	void loadTextures();
	void loadBuffers();
	void loadBackground();
	void setPauseScreen();

	sf::RectangleShape m_pauseScreen;
	sf::RectangleShape m_pauseButtons[3];

	sf::Texture m_textures[NUM_OF_PICS];
	std::vector < sf::Texture > m_bg;

	const std::string soundBuffers[NUM_OF_SOUNDS] = { "startGame.wav" , "victory.wav" , "fire.wav" , "ogre.wav" , "gate.wav" ,
													 "teleport.wav" , "gnome.wav" ,"countdown.wav" };

	const std::string objectTextures[NUM_OF_PICS] ={"king.png","kingUp.png","kingDown.png" , "kingLeft.png",
													"mage.png","mageUp.png","mageDown.png", "mageLeft.png",
													"warrior.png","warriorUp.png","warriorDown.png",  "warriorLeft.png",
													"thief.png", "thiefUp.png","thiefDown.png","thiefLeft.png",
													 "thiefKey.png" , "thiefUpKey.png", "thiefDownKey.png" , "thiefLeftKey.png",
													"wall.png", "throne.png", "fire.png", "ogre.png",
													"teleport.png", "gate.png", "key.png", "gnome.png",  "gift.png" };
};

