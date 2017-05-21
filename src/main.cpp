#include <iostream>
#include <GL/glut.h>

#include "globals.h"
#include "Controller.h"
#include "Ship.h"
#include "Shot.h"
#include "ShotManager.h"
#include "Alien.h"
#include "AlienManager.h"
using namespace std;

Ship player;
ShotManager shotManager;
AlienManager aliens;
void onDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_DOWN, ORTHO_UP);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Colocar todas as funcoes de .draw() aqui:
	player.draw();
	shotManager.draw();
	
	//desenha a tropa de aliens
	aliens.newAlienTroop(5, 5);	

	glutSwapBuffers();
}

void onTimerTick(int step)
{
	// Colocar todas as funcoes de .update() aqui:
	player.update(&shotManager);
	shotManager.update();

	glutTimerFunc(FRAME_TIME_MS, onTimerTick, step + 1);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{	

	// Initialize window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(400, 150);
	glutCreateWindow("Rosinha Invaders");

	// Register callback functions
	Controller::registerCallbacks();
	glutDisplayFunc(onDisplay);
	glutTimerFunc(0, onTimerTick, 0);

	glutMainLoop();

	return 0;
}
