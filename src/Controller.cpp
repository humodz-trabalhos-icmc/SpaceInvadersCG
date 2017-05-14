#include "Controller.h"
#include <GL/glut.h>

Controller gCtrl;

void Controller::registerCallbacks()
{
	// If key repeat is true, keeping a key down will trigger onKeyPress every frame
	glutIgnoreKeyRepeat(true);
	glutKeyboardFunc(onKeyPress);
	glutKeyboardUpFunc(onKeyUp);
}

void Controller::onKeyPress(unsigned char ascii, int x, int y)
{
	// Suppress "unused variable" warnings
	(void) x;
	(void) y;
	gCtrl.setKeyPressed(ascii, true);
}

void Controller::onKeyUp(unsigned char ascii, int x, int y)
{
	// Suppress "unused variable" warnings
	(void) x;
	(void) y;
	gCtrl.setKeyPressed(ascii, false);
}

#include <iostream>

void Controller::setKeyPressed(unsigned char ascii, bool state)
{
	Key key = KEY_NONE;

	switch(ascii)
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

	std::cout << ascii << (state ? ": DOWN" : ": UP") << std::endl;
	is_down[key] = state;
}
