#pragma once
#include "surface.h"
#include "template.h"

#include <SDL_scancode.h>
#include <vector>

class StartMenu
{
public:
	StartMenu() : cursor(new Tmpl8::Surface("assets/ball.png"), 1)
	{
		cursorLoc = { ScreenWidth / 2, ScreenHeight / 2 };
	};

	//~StartMenu();


	void KeyUp(int key);
	void KeyDown(int key);

	void MouseMove(int x, int y) { cursorLoc.x = static_cast<float>(x); cursorLoc.y = static_cast<float>(y); mouseMode = true; };
	void MouseUp(int key);
	void MouseDown(int key);

	void Render(Tmpl8::Surface& screen);

private:
	struct Button {
		int x1;
		int x2;
		int y1;
		int y2;

		int colour;
	};

	Tmpl8::Sprite cursor;
	Tmpl8::vec2 cursorLoc;

	const Button buttons[3][4] = {
		{
			{ static_cast<int>(ScreenWidth / 2.0f - 100), static_cast<int>(ScreenWidth / 2.0f + 100), 150, 250, 0x00ff00 },
			{ static_cast<int>(ScreenWidth / 2.0f - 100), static_cast<int>(ScreenWidth / 2.0f + 100), 300, 400, 0x00ff00 }
		},
		{
			{ 300, 400, 150, 250, 0xff },
			{ 300, 400, 300, 400, 0xff }
		}
	};

	bool mouseMode = true;

	int selectedTile = 0;
	int menuType = 0;
	
	int GetTile();

	void Start(Tmpl8::Surface& screen);
	void LevelSelector(Tmpl8::Surface& screen);
	void Settings(Tmpl8::Surface& screen);

	void ExecuteTile(int tile);

	enum Menu {
		start = 0,
		level = 1,
		settings = 2
	};

	

};

