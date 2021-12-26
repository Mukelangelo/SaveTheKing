#pragma once

#include <SFML/Graphics.hpp>

constexpr auto WINDOW_WIDTH = 1600;
constexpr auto WINDOW_HEIGHT = 800;
constexpr auto MENU_BUTTONS = 3;
constexpr auto NUM_OF_PICS = 10;
constexpr auto PLAYABLE = 4;

constexpr auto StartGame = 0;
constexpr auto Help = 1;
constexpr auto Exit = 2;


/*enum load
{
	load King , load_Mage , load_Warrior , load_Thief , load_Wall , load_Throne 
	load

	TO CONTINUE
};

*/

constexpr auto load_King = 0;
constexpr auto load_Mage = 1;
constexpr auto load_Warrior = 2;
constexpr auto load_Thief = 3;
constexpr auto load_Wall = 4;
constexpr auto load_Throne = 5;
constexpr auto load_Fire = 6;
constexpr auto load_Orge = 7;
constexpr auto load_Teleport = 8;
constexpr auto load_Gate = 9;

const std::string objectTextures[NUM_OF_PICS] = { "king.png", "mage.png", "warrior.png", "thief.png",
													"wall.jpg", "throne.jpg", "fire.jpg", "orge.jpg", "teleport.jpg", "gate.jpg" };
// add key
