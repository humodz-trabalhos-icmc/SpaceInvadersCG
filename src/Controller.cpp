#include "Controller.h"
#include "Shot.h"
#include "Ship.h"
#include <GL/glut.h>
#include <stdio.h>

Controller gCtrl;
Shot shotVec[6];

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
/*
// prepara um novo tiro do jogador
void Controller::shotPlayer(double x){

	if (gCtrl.isDown(KEY_FIRE) && !shotVec[0].getState()){
		shotVec[0].setState(true);
		shotVec[0].setPos(x - 0.25, -1.5);
	}
}

// redesenha todos os tiros de acordo com suas novas coordenadas
void Controller::updateShots(){
	int i;

	for (i=0; i < 6; i++)
		shotVec[i].draw();
}*/
