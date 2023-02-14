#pragma once
#include "surface.h"
#include "template.h"

#include <vector>
#include <SDL_scancode.h>

class Player
{
public:

	/// <summary>
	/// Constructor of the Player
	/// </summary>
	Player()
		: sprite(new Tmpl8::Surface("assets/ctankbase.tga"), 16)
	{
		pos = { Rand(ScreenWidth), Rand(ScreenHeight) };
		heading = 0;
		health = 100;
		ammo = 100;
	};

	/// <summary>
	/// Contructor of the Player with start location
	/// <param name="x">X coord of the Player</param>
	/// <param name="y">Y coord of the Player</param>
	/// <param name="_heading">Heading of the Player</param>
	/// </summary>
	explicit Player(float x, float y, int _heading)
		: sprite(new Tmpl8::Surface("assets/ctankbase.tga"), 16)
	{
		pos = { x, y };
		heading = _heading;
		health = 100;
		ammo = 100;
	}

	/// <summary>
	/// Activates when a control is released
	/// </summary>
	/// <param name="key">See SDL_Keycodes for input param</param>
	void KeyUp(int key);

	/// <summary>
	/// Activates when a control is pressed
	/// </summary>
	/// <param name="key">See SDL_Keycodes for input param</param>
	void KeyDown(int key);
	
	/// <summary>
	/// Tick for the Player Class
	/// </summary>
	/// <param name="dT">Delta time. Time difference between screen</param>
	void Update(float dT);

	/// <summary>
	/// Render the Sprites of the Player 
	/// </summary>
	/// <param name="screen">Screen surface where the sprite needs to be drawn on</param>
	void Render(Tmpl8::Surface& screen) {
		sprite.Draw(&screen, pos.x, pos.y);
	}

	/// <summary>
	/// Returns the players health
	/// </summary>
	/// <returns>Player Health 0 to 100</returns>
	int GetPlayerHealth() { return health; };

private:
	/// <summary>
	/// Removes health of the player
	/// </summary>
	/// <param name="amount">The amount that gets removed</param>
	void DeductHealth(int amount) { health -= amount; }

	/// <summary>
	/// Sets the player's health
	/// </summary>
	/// <param name="amount">The amount that the player's health will be set to</param>
	void SetPlayerHealth(int amount) { health = amount; }

	Tmpl8::Sprite sprite;
	Tmpl8::vec2 pos;
	int health;
	int ammo;
	int heading;

	const float speed = 100.0f;
	
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
};

