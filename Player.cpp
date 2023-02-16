#include "Player.h"

#include <SDL_scancode.h>



void Player::KeyUp(int key)
{
	switch (key) {
	case SDL_SCANCODE_W:
		upKey = false;
		break;
	case SDL_SCANCODE_S:
		downKey = false;
		break;
	case SDL_SCANCODE_A:
		leftKey = false;
		break;
	case SDL_SCANCODE_D:
		rightKey = false;
		break;
	case SDL_SCANCODE_LSHIFT:
		speed = 100.0f;
	default:
		break;
	}
}

void Player::KeyDown(int key)
{
	switch (key) {
	case SDL_SCANCODE_W:
		upKey = true;
		break;
	case SDL_SCANCODE_S:
		downKey = true;
		break;
	case SDL_SCANCODE_A:
		leftKey = true;
		break;
	case SDL_SCANCODE_D:
		rightKey = true;
		break;
	case SDL_SCANCODE_LSHIFT:
		if (speed < 200.0f) {
			speed = 200.0f;
		}
		break;
	default:
		break;
	}
}

void Player::Move(int spriteFrame, float dT, int plusX, int plusY) {
	sprite.SetFrame(spriteFrame);

	switch (plusX) {
	case 0:
		// Dont move
		break;
	case 1:
		// Move left
		if (pos.x > 100) {
			pos.x -= speed * dT;
		}
		break;
	case 2:
		// Move right
		if (pos.x + sprite.GetWidth() < ScreenWidth - 100) {
			pos.x += speed * dT;
		}
		break;
	default:
		break;
	}

	switch (plusY) {
	case 0:
		// Dont move
		break;
	case 1:
		// Move left
		if (pos.y > 100) {
			pos.y -= speed * dT;
		}
		break;
	case 2:
		// Move right
		if (pos.y + sprite.GetHeight() <= ScreenHeight - 100) {
			pos.y += speed * dT;
		}
		break;
	default:
		break;
	}
}

void Player::Update(float dT)
{
	if (upKey && leftKey) {
		Move(topleft, dT, 1, 1);
		return;
	}

	if (upKey && rightKey) {
		Move(topright, dT, 2, 1);
		return;
	}

	if (downKey && leftKey) {
		Move(bottomleft, dT, 1, 2);
		return;
	}

	if (downKey && rightKey) {
		Move(bottomright, dT, 2, 2);
		return;
	}
	 
	if (upKey) {
		Move(top, dT, 0, 1);
	}

	if (downKey) {
		Move(bottom, dT, 0, 2);
	}
	
	if (leftKey) {
		Move(left, dT, 1, 0);
	}

	if (rightKey) {
		Move(right, dT, 2, 0);
	}
}

void Player::Shoot() {

}
