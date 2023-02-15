#pragma once
#include "surface.h"
#include "template.h"

#include <SDL_scancode.h>

class StartMenu
{
public:
	StartMenu() : cursor(new Tmpl8::Surface("assets/ball.png"), 1)
	{
		cursorLoc = { ScreenWidth / 2, ScreenHeight / 2 };
	};

	~StartMenu();

	void KeyUp(int key);
	void KeyDown(int key);

	void MouseMove(int x, int y);
	void MouseUp(int key);
	void MouseDown(int key);

	void Draw(Tmpl8::Surface& screen);

private:
	Tmpl8::Sprite cursor;
	Tmpl8::vec2 cursorLoc;

	int menuType;

	enum menu {
		start = 0,
		level = 1,
		settings = 2
	};

};

