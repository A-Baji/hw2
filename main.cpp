#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0, 0, 3, 1}; // TODO: Your code here! setup a proper camera position. It should be 4 dimentions homogeneous coordinate, first three elements represent position and 4th element should be 1.
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // Defaults to first problem

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() { // Teapot circle
	double radius = 0.7;
	int numPots = 10;
	double theta = (M_PI*2) / numPots; // theta is 2pi divided the number of points on the circle
	double angle;
	double degree;

	for (int i = 0; i < numPots; i++) {
		angle = (theta * i); // Radians
		degree = angle * (180 / M_PI); // Degrees
		glPushMatrix();
			// Translate matrix to equidistant points on a circle of radius 0.7
			glTranslatef(radius * cos(angle), radius * sin(angle), 0.0);

			// Rotate matrix by the angle of the current point's position
			glRotatef(degree, 0.0, 0.0, 1.0);

			// Draw a size .15 tea pot with the current matrix.
			glutSolidTeapot(0.2);
		glPopMatrix();
	}
}

void problem2() { // Steps
	int numSteps = 15;
	double height;

	glPushMatrix();
		// Shift overall matrix to the left to center the cubes
		glTranslatef(-1.2, 0.0, 0.0);
		for (int i = 1; i <= numSteps; i++) { // For every column
			height = 0;
			for (int j = 0; j < i; j++) { // For every cube per column
				height += j * 0.003;
				glPushMatrix();
					// Move matrix to current height
					glTranslatef(i*0.15, height, 0.0);

					// Draw a size .1 cube
					glutSolidCube(0.15);
				glPopMatrix();
			}
		}
	glPopMatrix();
}

void problem3() { // Happy Sun (Shine sprite from Super Mario Sunshine)
	double radius = 0.38;
	int numSpikes = 8;
	double theta = (M_PI * 2) / numSpikes;
	double angle;
	double degree;

	// Draw main sphere
	glutSolidSphere(0.4, 100, 100);

	// Draw spikes around sphere
	for (int i = 0; i < numSpikes; i++) {
		angle = (theta * i);
		degree = angle * (180 / M_PI);
		glPushMatrix();
			glTranslatef(radius * cos(angle), radius * sin(angle), 0.0);
			glRotatef(degree, 0.0, 0.0, 1.0); 
			glRotatef(90, 0.0, 1.0, 0.0);
			glutSolidCone(0.15, 0.5, 100, 100);
		glPopMatrix();
	}

	// Draw balls on end of spikes
	radius = 0.88;
	for (int i = 0; i < numSpikes; i++) {
		angle = (theta * i);
		glPushMatrix();
			glTranslatef(radius * cos(angle), radius * sin(angle), 0.0);
			glutSolidSphere(0.1, 100, 100);
		glPopMatrix();
	}

	// Draw left eye
	glPushMatrix();
		glTranslatef(-0.125, 0.1, .25);
		glRotatef(90, 0, 1, 0);
		glutSolidTorus(0.075, 0.075, 100, 100);
	glPopMatrix();

	// Draw right eye
	glPushMatrix();
		glTranslatef(0.125, 0.1, 0.25);
		glRotatef(90, 0, 1, 0);
		glutSolidTorus(0.075, 0.075, 100, 100);
	glPopMatrix();

	// Draw smile
	glPushMatrix();
		glTranslatef(0, -0.09, 0.275);
		glRotatef(-12, 1, 0, 0);
		glutSolidTorus(0.075, 0.1, 100, 100);
	glPopMatrix();

}

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Use glViewport() and gluPerspective() to setup projection matrix.
	glViewport(0, 0, windowWidth, windowHeight);
	gluPerspective(45, double(windowWidth) / double(windowHeight), 1, 100);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Use gluLookAt() to setup model-view matrix.
	gluLookAt(0, 0, 2.75, 0, 0, 0, 0, 1, 0);


	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (double(x) - lastPos[0]) * .1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (double(y) - lastPos[1]) * .1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	// Use key to switch between different scene, and set q, Q and Escape key as quit. 
	switch (key) {
	case '1':
		curProblem = 1;
		glutPostRedisplay();
		break;

	case '2':
		curProblem = 2;
		glutPostRedisplay();
		break;

	case '3':
		curProblem = 3;
		glutPostRedisplay();
		break;

	case 'q':
		exit(1);

	case 'Q':
		exit(1);

	case 27:
		exit(1);
	}
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}