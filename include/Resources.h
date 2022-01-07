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
	

	sf::Texture m_textures[NUM_OF_PICS];
	sf::Texture m_bg;

	const std::string soundBuffers[NUM_OF_SOUNDS] = { "startGame.wav" , "victory.wav" , "fire.wav" , "ogre.wav" , "gate.wav" ,
													 "teleport.wav" , "gnome.wav" ,"countdown.wav" };

	const std::string objectTextures[NUM_OF_PICS] = { "king.png", "mage.png", "warrior.png", "thief.png",
													"wall.png", "throne.png", "fire.png", "ogre.png",
													"teleport.png", "gate.png", "key.png", "gnome.png", "thiefKey.png", "gift.png" };
};


/* needed sounds :
	throne
	teleport
	gnome death
	time add / dec
	start game sound
	music of ticking clock

*/