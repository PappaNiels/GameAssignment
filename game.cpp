#include "game.h"
#include "surface.h"
#include "template.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace Tmpl8
{
    //Surface tiles("assets/nc2tiles.png");
    //Sprite tank(new Surface("assets/ctankbase.tga"), 16);

    //targets test;

    void Game::Init() {
        //test.GoToCoord();
        

       
    }
    void Game::Shutdown() {}

    void Game::MouseMove(int x, int y) {
        mousex = x;
        mousey = y; 


        //test.MouseMove(x, y);
    }

    //Game::Game() {
        //targets test;
    //}

    void Game::MouseDown(int key) {
        //test.MouseDown(key);
    }
    
    void Game::MouseUp(int key) {
        //test.MouseUp(key);
    }

    void Game::KeyDown(int key) {
        test.KeyDown(key);
    }
    void Game::KeyUp(int key) {
        test.KeyUp(key);
    }

    //Game::Game() {
    //    //for (int i = 0; i < 3; i++) {
    //    targets test;
    //    target.push_back(std::move(test));
    //    //}
    //};

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);

        deltaTime /= 1000.0f;

        //if (GetAsyncKeyState(VK_UP)) {
        //    //test.MoveUp();
        //}
        //if (GetAsyncKeyState(VK_DOWN)) {
        //    test.MoveDown();
        //}
        //if (GetAsyncKeyState(VK_LEFT)) {
        //    test.MoveLeft();
        //}
        //if (GetAsyncKeyState(VK_RIGHT)) {
        //    test.MoveRight();
        //}
        //if (GetAsyncKeyState(VK_DELETE)) {}

        test.Update(deltaTime);
        test.Render(*screen);
    }
};

