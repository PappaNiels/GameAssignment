#include "game.h"
#include "surface.h"
#include "template.h"

#include <iostream>



//#define WIN32_LEAN_AND_MEAN
//#include <windows.h>

namespace Tmpl8
{

	static Game* gameObj = nullptr;

	Game::Game() : screen(nullptr) {
		gameObj = this;
	}

	//Game::~Game() {
	//    gameObj = nullptr;
	//}

	Game& Game::GetGame() {
		return *gameObj;
	}

	void Game::Init() {
		//GetScreenRes();
	}
	void Game::Shutdown() {}

	void Game::MouseMove(int x, int y) {
		//test.MouseMove(x, y);
		menu.MouseMove(x, y);
	}

	void Game::MouseDown(int key) {
		//test.MouseDown(key);
		menu.MouseDown(key);
	}

	void Game::MouseUp(int key) {
		//test.MouseUp(key);
	}

	void Game::KeyDown(int key) {
		switch (gameState)
		{
		case mainmenu:
			menu.KeyDown(key);

			break;
		case game:
			test.KeyDown(key);

			break;
		case pause:

			break;
		default:
			break;
		}
	}
	void Game::KeyUp(int key) {
		test.KeyUp(key);
	}

	void Game::Tick(float deltaTime)
	{
		screen->Clear(0);

		deltaTime /= 1000.0f;

		switch (gameState)
		{
		case mainmenu:

			menu.Render(*screen);
			break;
		case game:

			break;
		case pause:

			break;
		default:
			break;
		}


		test.Update(deltaTime);
		test.Render(*screen);
	}
};

