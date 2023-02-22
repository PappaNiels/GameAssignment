#pragma once

#include "template.h"
#include "Player.h"
#include "StartMenu.h"

#include <vector>

namespace Tmpl8 {

class Surface;
class Game
{
public:
	
	Game();

	//Game(const Game& copy) = delete;
	//Game& operator=(const Game& copy) = delete;

	//Game(Game&& copy) = default;
	//Game& operator=(Game&& copy) = default;

	/// <summary>
	/// Returns the game object
	/// </summary>
	/// <returns></returns>
	static Game& GetGame();

	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp(int button);
	void MouseDown(int button);
	void MouseMove(int x, int y);
	void KeyUp(int key);
	void KeyDown(int key);
	
	/// <summary>
	/// Sets the game state of the game
	/// </summary>
	/// <param name="state">: 0 = Main menu, 1 = Game, 2 = Pause menu</param>
	void SetGameState(int state) { gameState = state; }

private:
	Surface* screen;

	//int mousex = 0;
	//int mousey = 0;
	int gameState = 0;
	
	StartMenu menu;
	Player test;

	enum gameStates {
		mainmenu = 0, 
		game = 1,
		pause = 2
	};
};

}; // namespace Tmpl8