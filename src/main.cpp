#include <iostream>
#include <GL/glut.h>

void onDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-3, 3, -2, 2);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_QUADS);
	{
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f( 1.0,  1.0);
		glVertex2f(-1.0,  1.0);
		glVertex2f(-1.0, -1.0);
		glVertex2f( 1.0, -1.0);
	}
	glEnd();

	glutSwapBuffers();
}

void onKeyPress(unsigned char key, int mouse_x, int mouse_y)
{

}

void onSpecialKeyPress(int key, int x, int y)
{

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
	glutDisplayFunc(onDisplay);
	glutKeyboardFunc(onKeyPress);
	glutSpecialFunc(onSpecialKeyPress);
	glutTimerFunc(0, onTimerTick, 0);

	glutMainLoop();

	return 0;
}
