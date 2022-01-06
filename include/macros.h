#pragma once

#include <SFML/Graphics.hpp>

constexpr auto WINDOW_WIDTH = 1600;
constexpr auto WINDOW_HEIGHT = 800;
constexpr auto BAR_SIZE = 100;
constexpr auto MENU_BUTTONS = 3;
constexpr auto NUM_OF_PICS = 14;
constexpr auto PLAYABLE = 4;

enum MenuButtons
{
	StartGame, Help, Exit
};

enum LoadTextures
{
	load_King , load_Mage , load_Warrior , load_Thief , load_Wall , load_Throne,
	load_Fire, load_Orge, load_Teleport, load_Gate, load_Key, load_Gnome, load_ThiefKey, load_Gift
};

enum class CollisionStatus
{
	Destroy, Good, Not_Valid, Won, Teleport, Gift, Ogre
};