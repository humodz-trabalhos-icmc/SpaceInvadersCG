#include <GL/glut.h>
#include <ctype.h>

#include "Controller.h"
#include "Shot.h"
#include "Ship.h"

Controller gCtrl; // teclad od usuário


// método que registra as callbacks
void Controller::registerCallbacks()
{
	// If key repeat is true, keeping a key down will trigger onKeyPress every frame
	glutIgnoreKeyRepeat(true);
	glutKeyboardFunc(onKeyPress);
	glutKeyboardUpFunc(onKeyUp);
}

// método do evento no pressionar do teclado
void Controller::onKeyPress(unsigned char ascii, int x, int y)
{
	// Suppress "unused variable" warnings
	(void) x;
	(void) y;
	// Mark key as pressed (true)
	gCtrl.setKeyPressed(ascii, true);
}
// método do evento quando a tecla é solta
void Controller::onKeyUp(unsigned char ascii, int x, int y)
{
	// Suppress "unused variable" warnings
	(void) x;
	(void) y;
	// Mark key as released (false)
	gCtrl.setKeyPressed(ascii, false);
}
// método handler do evento da tecla pressionada
void Controller::setKeyPressed(unsigned char ascii, bool state)
{
	Key key = KEY_NONE;

	switch(tolower(ascii))
	{
		case 'a':
			key = KEY_LEFT;
			break;
		case 'd':
			key = KEY_RIGHT;
			break;
		case ' ':
			key = KEY_FIRE;
			break;
	}

	is_down[key] = state;
}
