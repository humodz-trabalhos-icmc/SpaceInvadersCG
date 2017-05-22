#include <iostream>
#include <time.h>
#include <GL/glut.h>

#include "globals.h"
#include "Controller.h"
#include "Ship.h"
#include "Shot.h"
#include "ShotManager.h"
#include "Alien.h"
#include "AlienManager.h"
using namespace std;

Ship player; // objeto global do player
ShotManager shotManager; // objeto gloabl que gerencia os tiros das naves
AlienManager aliens; // objeto global que gerencia os aliens

// método que lida com o display / rendering
void onDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_DOWN, ORTHO_UP);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// desenhando os objetos
	player.draw();
	aliens.draw();
	shotManager.draw();

	glutSwapBuffers();
}

// método de redesenho pelo frame_time
void onTimerTick(int step)
{
	player.update(&shotManager);
	aliens.update(&shotManager);
	shotManager.update();

	glutTimerFunc(FRAME_TIME_MS, onTimerTick, step + 1);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{

	//initialize seed
	srand(time(NULL));

	// Initialize window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(400, 150);
	glutCreateWindow("Rosinha Invaders");

	//desenha a tropa de aliens
	aliens.newAlienTroop(5, 5);

	// Register callback functions
	Controller::registerCallbacks();
	glutDisplayFunc(onDisplay);
	glutTimerFunc(0, onTimerTick, 0);
	glutMainLoop(); //inicializa loop do jogo

	return 0;
}
