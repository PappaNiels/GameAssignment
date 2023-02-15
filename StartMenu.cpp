#include "StartMenu.h"


void StartMenu::Draw(Tmpl8::Surface& screen) {
	cursor.Draw(&screen, cursorLoc.x, cursorLoc.y);

	switch (menuType) {
	case start:

		break;
	case level:

		break;
	case settings:

		break;
	}
}