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
	sf::Texture* getTexture(int i , int j);
	sf::Texture* getTexture(int i);
	sf::Texture* getBackground(int index);
	sf::Font* getFont();
	void drawPauseScreen(sf::RenderWindow& window);
	void playMusic();
	void playSound(int index);
	int HandleClick(const sf::Vector2f location);

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	sf::SoundBuffer m_buffers[NUM_OF_SOUNDS];
	sf::Sound m_sounds[NUM_OF_SOUNDS];
	sf::Music m_music;

	bool Clicked(int index, const sf::Vector2f location);
	void loadTextures();
	void loadBuffers();
	void loadBackground();
	void setPauseScreen();
	void SetButtons();

	sf::RectangleShape m_pauseWindow;
	sf::RectangleShape m_pauseButtons[MENU_BUTTONS];
	sf::Text m_pauseText;

	sf::Texture m_pauseTextures[MENU_BUTTONS];

	sf::Texture m_textures[NUM_OF_PICS][DIRECTIONS];
	std::vector < sf::Texture > m_bg;
	sf::Font m_font;

	const std::string buttonTextures[MENU_BUTTONS] = { "home-button.png" , "restart-button.png" , "music-button.png" };

	const std::string soundBuffers[NUM_OF_SOUNDS] = { "startGame.wav" , "victory.wav" , "fire.wav" , "ogre.wav" , "gate.wav" ,
													  "teleport.wav" , "gnome.wav" ,"countdown.wav" };

	const std::string objectTextures[NUM_OF_PICS][DIRECTIONS] = { {"king.png","kingUp.png","kingDown.png" , "kingLeft.png"},
																  {"mage.png","mageUp.png","mageDown.png", "mageLeft.png"},
																  {"warrior.png","warriorUp.png","warriorDown.png",  "warriorLeft.png"},
																  {"thief.png", "thiefUp.png","thiefDown.png","thiefLeft.png"},
																  {"thiefKey.png" , "thiefUpKey.png", "thiefDownKey.png" , "thiefLeftKey.png"},
																  {"wall.png"}, {"throne.png"}, {"fire.png"}, {"ogre.png"},
																  {"teleport.png"}, {"gate.png"}, {"key.png"}, {"gnome.png"}, { "gift.png"} };
};

