#include <GL/freeglut.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include "MasterManager.h"

double rotate_x = 0, rotate_y = 0;
MasterManager* manager = new MasterManager();

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);

	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, -3.0f, 3.0f);
	else  glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -3.0f, 3.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluPerspective(50, h / w, 0.0, 10.0 );
	else  gluPerspective(50, w / h, 0.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

void display(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	manager->gameGo();

	glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
    manager->key(key);
	glutPostRedisplay();
}

void timer(int value){

	manager->physicsGo();
	glutPostRedisplay();

	glutTimerFunc(5, timer, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CubeEx");

	glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
	glutTimerFunc(100, timer, 0);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
