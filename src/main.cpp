#include <iostream>
#include <GL/glut.h>

#include "Controller.h"
#include "CollisionBox.h"

void onDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 400);

	// Testing box rendering
	CollisionBox box1({100, 100}, 30, 40);
	CollisionBox box2({350, 200}, 90, 90);
	CollisionBox box3({400, 150}, 60, 20);

	box1.renderOutline();
	box2.renderOutline();
	box3.renderOutline();

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
