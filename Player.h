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
		pos = { 150, 150 };
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
	/// Detects when a control of the keyboard is released
	/// </summary>
	/// <param name="key">See SDL_Keycodes for input param</param>
	void KeyUp(int key);

	/// <summary>
	/// Detects when a control of the keyboard is pressed
	/// </summary>
	/// <param name="key">See SDL_Keycodes for input param</param>
	void KeyDown(int key);
	
	/// <summary>
	/// Detects if a mouse button has been released
	/// </summary>
	/// <param name="key">: Mouse button id:
	/// 1 = Left mouse button
	/// 2 = Middle mouse button
	/// 3 = Right mouse button
	///  </param>
	void MouseUp(int key) {
		switch (key) {
		case 1:

			break;
		case 2:
			break;
		case 3:

			break;
		default:
			break;
		}
	}

	/// <summary>
	/// Detects if a mouse button has been pressed
	/// </summary>
	/// <param name="key">: Mouse button id:
	/// 1 = Left mouse button
	/// 2 = Middle mouse button
	/// 3 = Right mouse button
	///  </param>
	void MouseDown(int key) {
		switch (key) {
		case 1:
			Shoot();
			break;
		case 2:
			break;
		case 3:

			break;
		default:
			break;
		}
	}

	/// <summary>
	/// Tick for the Player Class
	/// </summary>
	/// <param name="dT">: Delta time. Time difference between screen</param>
	void Update(float dT);

	/// <summary>
	/// Render the Sprites of the Player 
	/// </summary>
	/// <param name="screen">Screen surface where the sprite needs to be drawn on</param>
	void Render(Tmpl8::Surface& screen) {
		sprite.Draw(&screen, static_cast<int>(pos.x), static_cast<int>(pos.y));

		screen.Box(100, 100, ScreenWidth - 100, ScreenHeight - 100, 0x00ffffff);
	}

	/// <summary>
	/// Returns the players health
	/// </summary>
	/// <returns>Player Health 0 to 100</returns>
	int GetPlayerHealth() { return health; };
protected: 
	/// <summary>
	/// Shoot a buttet where you are looking at
	/// </summary>
	void Shoot();

private:
	/// <summary>
	/// Removes health of the player
	/// </summary>
	/// <param name="amount">: The amount that gets removed</param>
	void DeductHealth(int amount) { health -= amount; }

	/// <summary>
	/// Sets the player's health
	/// </summary>
	/// <param name="amount">: The amount that the player's health will be set to</param>
	void SetPlayerHealth(int amount) { health = amount; }

	/// <summary>
	/// Moves the sprite and sets the desired frame of the sprite
	/// </summary>
	/// <param name="spriteFrame">: The frame of the sprite that will be set</param>
	/// <param name="dT">: Delta time</param>
	/// <param name="plusX">: Move type X coord
	///		0 = Don't move
	///		1 = Move left (-)
	///		2 = Move right (+)
	/// </param>
	/// <param name="plusY">: Move type Y coord
	///		0 = Don't move
	///		1 = Move left (-)
	///		2 = Move right (+)
	/// </param>
	void Move(int spriteFrame, float dT, int plusX, int plusY);

	Tmpl8::Sprite sprite;
	Tmpl8::vec2 pos;
	int health;
	int ammo;
	int heading;

	float speed = 100.0f;
	
	bool upKey = false;
	bool downKey = false;
	bool leftKey = false;
	bool rightKey = false;

	enum dir {
		top = 0,
		topright = 2,
		right = 4,
		bottomright = 6,
		bottom = 8,
		bottomleft = 10,
		left = 12,
		topleft = 14
	};
};

