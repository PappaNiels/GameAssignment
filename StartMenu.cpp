#include "StartMenu.h"
#include "game.h"

#include <SDL_scancode.h>

int StartMenu::GetTile() {
	for (int i = 0; i < 3; i++) {
		if (cursorLoc.x > buttons[menuType][i].x1 && cursorLoc.x < buttons[menuType][i].x2 && cursorLoc.y > buttons[menuType][i].y1 && cursorLoc.y < buttons[menuType][i].y2) {
			return i;
		}
	}

	return NULL;
}

void StartMenu::KeyUp(int key) {

}

void StartMenu::KeyDown(int key) {
	if (mouseMode) {
		mouseMode = false;
		return;
	}

	switch (key)
	{
	case SDL_SCANCODE_RETURN:
		this->ExecuteTile(-1);
		break;
	case SDL_SCANCODE_UP:
		if (selectedTile > 0) {
			selectedTile--;
		}
		break;
	case SDL_SCANCODE_DOWN:
		if (selectedTile < 1) {
			selectedTile++;
		}
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
		this->ExecuteTile(this->GetTile());
	default:
		break;
	}
}

void StartMenu::ExecuteTile(int tile) {
	if (tile != -1) {
		selectedTile = tile;
	}


	switch (menuType) {
	case Menu::start:
		switch (selectedTile)
		{
		case 0: // Start 
			menuType = level;
			break;
		case 1: // Settings / Credits

			break;
		case 2: // Exit

			break;
		default:
			break;
		}
	case level:
		switch (selectedTile)
		{
		case 0: // Level one
			Tmpl8::Game::GetGame().SetGameState(1);
			break;
		case 1: // Level two

			break;
		case 2: // Level three

			break;
		case 3: // Exit to Main Menu

			break;
		default:
			break;
		}
	case settings:

	default:
		break;
	}
}

void StartMenu::Start(Tmpl8::Surface& screen) {
	// tiles 
	for (int i = 0; i < 2; i++) {
		//(&screen)->Box(startButtons[i][1], startButtons[i][2], startButtons[i][3], startButtons[i][4], startButtons[i][5]);
	}

	if (!mouseMode) {
		// box
	}
}

void StartMenu::LevelSelector(Tmpl8::Surface& screen) {

}

void StartMenu::Settings(Tmpl8::Surface& screen) {

}

void StartMenu::Render(Tmpl8::Surface& screen) {
	for (const Button b : buttons[menuType]) {
		screen.Bar(b.x1, b.y1, b.x2, b.y2, b.colour);
	}

	if (mouseMode) {
		cursor.DrawScaled(static_cast<int>(cursorLoc.x), static_cast<int>(cursorLoc.y), 30, 30, &screen);

		for (const Button b : buttons[menuType]) {
			if (cursorLoc.x > b.x1 && cursorLoc.x < b.x2 && cursorLoc.y > b.y1 && cursorLoc.y < b.y2) {
				screen.Box(b.x1 - 10, b.y1 - 10, b.x2 + 10, b.y2 + 10, 0xffffff);
			}
		}

	}
	else {
		screen.Box(buttons[menuType][selectedTile].x1 - 10, buttons[menuType][selectedTile].y1 - 10, buttons[menuType][selectedTile].x2 + 10, buttons[menuType][selectedTile].y2 + 10, 0xffffff);
	}


	switch (menuType) {
	case start:
		//this->Start(screen);
		break;
	case level:

		break;
	case settings:

		break;
	default:
		break;
	}
}