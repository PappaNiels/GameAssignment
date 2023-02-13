#pragma once
#include "game.h"
#include "surface.h"
#include "template.h"
#include <stdio.h>

namespace Tmpl8 {
	class targets
	{
	public:
		targets() : sprite(new Surface("assets/ctankbase.tga"), 16) {
			coords.x = IRand(ScreenWidth);
			coords.y = IRand(ScreenHeight);
		}
		

		void MoveUp() { coords.y--; };
		void MoveDown() { coords.y++; };
		void MoveLeft() { coords.x--; };
		void MoveRight() { coords.x++; };
		void Update(Surface* screen) ;
		void MouseMove(int x, int y) { mouse.x = x; mouse.y = y; };
		void KeyUp(int key);
		void KeyDown(int key);
		void MouseUp(int key);
		void MouseDown(int key);

		// Debug
		void GoToCoord();

		void SetColour(int _colour) {
			colour = _colour;
		}

	private:
		vec2 coords;
		vec2 mouse;
		Sprite sprite;
		int colour = 0xffffff;
		

		vec2 GetRandomCoord();
	};

};

