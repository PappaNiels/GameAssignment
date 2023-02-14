#pragma once

#include "template.h"
#include "targets.h"
#include "Player.h"

#include <vector>

namespace Tmpl8 {

class Surface;
class Game
{
public:
	
	//Game();

	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp(int button);
	void MouseDown(int button);
	void MouseMove(int x, int y);
	void KeyUp(int key);
	void KeyDown(int key);
	
private:
	Surface* screen;
	int mousex;
	int mousey;
	Player test;
	//std::vector<targets> target;
};

}; // namespace Tmpl8