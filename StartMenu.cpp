#include "StartMenu.h"

#include <SDL_scancode.h>

void StartMenu::KeyUp(int key) {

}

void StartMenu::KeyDown(int key) {
	mouseMode = false;

	switch (key)
	{
	case SDL_SCANCODE_RETURN:
		break;
	case SDL_SCANCODE_UP:
		break;
	case SDL_SCANCODE_DOWN:
		break;
	case SDL_SCANCODE_LEFT:
		break;
	case SDL_SCANCODE_RIGHT:
		break;
	default:
		break;
	}
}

void StartMenu::MouseUp(int key) {

}

void StartMenu::MouseDown(int key) {
	switch (key)
	{
	case 1:

	default:
		break;
	}
}

void StartMenu::Start(Tmpl8::Surface& screen) {
	// tiles 


	if (!mouseMode) {
		// box
	}
}

void StartMenu::LevelSelector(Tmpl8::Surface& screen) {

}

void StartMenu::Settings(Tmpl8::Surface& screen) {

}

void StartMenu::Draw(Tmpl8::Surface& screen) {
	if (mouseMode) {
		cursor.Draw(&screen, static_cast<int>(cursorLoc.x), static_cast<int>(cursorLoc.y));
	}

	switch (menuType) {
	case start:

		break;
	case level:

		break;
	case settings:

		break;
	default:
		break;
	}
}