#include "Player.h"

#include <SDL_scancode.h>

void Player::KeyUp(int key)
{
	switch (key) {
	case SDL_SCANCODE_W:
		up = false;
		break;
	case SDL_SCANCODE_S:
		down = false;
		break;
	case SDL_SCANCODE_A:
		left = false;
		break;
	case SDL_SCANCODE_D:
		right = false;
		break;
	}
}

void Player::KeyDown(int key)
{
	switch (key) {
	case SDL_SCANCODE_W:
		up = true;
		break;
	case SDL_SCANCODE_S:
		down = true;
		break;
	case SDL_SCANCODE_A:
		left = true;
		break;
	case SDL_SCANCODE_D:
		right = true;
		break;
	}
}

void Player::Update(float dT)
{
	if (up) {
		sprite.SetFrame(0);
		pos.y -= speed * dT;
	}

	if (down) {
		sprite.SetFrame(8);
		pos.y += speed * dT;
	}
	if (left) {
		sprite.SetFrame(12);
		pos.x -= speed * dT;
	}

	if (right) {
		sprite.SetFrame(4);
		pos.x += speed * dT;
	}
}
