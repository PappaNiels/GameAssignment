#include "targets.h"
#include "surface.h"
#include "game.h"

#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#include <SDL_scancode.h>

namespace Tmpl8 {
	vec2 targets::GetRandomCoord() {
		vec2 retval;

		retval.x = static_cast<float>(rand() % (ScreenWidth - sprite.GetWidth()) + 1);
		retval.y = static_cast<float>(rand() % (ScreenHeight - sprite.GetHeight()) + 1);

		//coords = retval;
		return retval;
	}

	void targets::GoToCoord() {
		vec2 rCoord = GetRandomCoord();
		vec2 delta = {0.0f, 0.0f};
		int x = 0;

		delta.x = rCoord.x - coords.x;
		delta.y = rCoord.y - coords.y;
		
		delta.x /= 1000.0f;
		delta.y /= 1000.0f;


		while (x < 1000) {
			coords.x += delta.x;
			coords.y += delta.y;

			//coords += delta;

			x++;
			//Sleep(50);
		}

		Sleep(1000);
			
		GoToCoord();

	}

	void targets::Update(Surface* screen) {
		//printf("%f, %f\n", coords.x, coords.y);
		sprite.Draw(screen, static_cast<int>(coords.x), static_cast<int>(coords.y));

		if (mouse.x > coords.x && mouse.x < (coords.x + sprite.GetWidth()) && mouse.y > coords.y && mouse.y < (coords.y + sprite.GetHeight())) {
			colour = 0xff0000;
		}
		else {
			colour = 0xffffff;
		}

		screen->Box(coords.x, coords.y, coords.x + sprite.GetWidth(), coords.y + sprite.GetHeight(), colour);
		screen->Line(0, mouse.y, ScreenWidth, mouse.y, 0xff);
		screen->Line(mouse.x, 0, mouse.x, ScreenHeight, 0xff);
		//screen->Bar(static_cast<int>(coords.x), static_cast<int>(coords.y), static_cast<int>(coords.x + 10.0f), static_cast<int>(coords.y + 10.0f), 0xff0000);
	}

	void targets::KeyUp(int key) {
		switch (key) {
			case SDL_SCANCODE_E:
				break;
			case 2:
			default:
				break;

		}

	}

	void targets::KeyDown(int key) {

	}

	void targets::MouseUp(int key) {
		switch (key) {

		default:
			break;
		}
	}
	
	void targets::MouseDown(int key) {
		printf("%i \n", key);
		switch (key) {
		case 1:
			break;
		case 3:
			break;
		default:
			break;
		}
	}
};
