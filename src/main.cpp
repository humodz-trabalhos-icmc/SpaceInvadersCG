#include <iostream>
#include <GL/glut.h>
#include "Controller.h"
#include "Ship.h"
#include "Shot.h"
using namespace std;

Ship ship;

void onDisplay(void)
{	
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-3, 3, -2, 2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// redesenha a nave
	ship.draw();
	// prepara um novo tiro do jogador
	gCtrl.shotPlayer(ship.getPos());
	// prepara novos tiros pelos inimigos
	//gCtrl.shotEnemys();
	// redesenha todos os tiros da tela
	gCtrl.updateShots();

	glutSwapBuffers();
}

void onTimerTick(int step)
{
	glutTimerFunc(1000 / 30, onTimerTick, step + 1);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	// Initialize window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 400);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("Rosinha Invaders");

	// Register callback functions
	Controller::registerCallbacks();
	glutDisplayFunc(onDisplay);
	glutTimerFunc(0, onTimerTick, 0);

	glutMainLoop();

	return 0;
}
