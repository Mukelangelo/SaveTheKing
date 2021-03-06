#pragma once

#include <SFML/Graphics.hpp>

constexpr auto WINDOW_WIDTH = 1600;
constexpr auto WINDOW_HEIGHT = 800;
constexpr auto STAGE_TIME = 150;
constexpr auto BAR_SIZE = 100;
constexpr auto MENU_BUTTONS = 3;
constexpr auto NUM_OF_PICS = 14;
constexpr auto DIRECTIONS = 4;
constexpr auto NUM_OF_SOUNDS = 8;
constexpr auto PLAYABLE = 4;

enum MenuButtons
{
	StartGame, Help, Exit
};

enum PauseButtons
{
	Home , Restart , Music
};

enum Directions
{
	Right, Up , Down, Left
};

enum LoadTextures
{
	load_King, load_Mage, load_Warrior, load_Thief , load_ThiefKey,
	load_Wall , load_Throne, load_Fire, load_Orge, load_Teleport, load_Gate,
	load_Key, load_Gnome, load_Gift
};

enum class CollisionStatus
{
	Destroy, Good, Not_Valid, Won, Teleport, Gift, Ogre, Block
};

enum LoadSoundBuffers
{
	start_sound , victory_sound , fire_sound , ogre_sound , gate_sound , teleport_sound , gnome_sound , countdown_sound
};