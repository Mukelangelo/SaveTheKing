#pragma once

#include <SFML/Graphics.hpp>

constexpr auto WINDOW_WIDTH = 1600;
constexpr auto WINDOW_HEIGHT = 800;
constexpr auto MENU_BUTTONS = 3;
constexpr auto NUM_OF_PICS = 10;
constexpr auto PLAYABLE = 4;

enum MenuButtons
{
	StartGame, Help, Exit
};

enum LoadTextures
{
	load_King , load_Mage , load_Warrior , load_Thief , load_Wall , load_Throne,
	load_Fire, load_Orge, load_Teleport, load_Gate
};

const std::string objectTextures[NUM_OF_PICS] = { "king.png", "mage.png", "warrior.png", "thief.png",
													"wall.jpg", "throne.png", "fire.png", "ogre.png", "teleport.png", "gate.png" };
// add key

// ogre + gate need normal resize