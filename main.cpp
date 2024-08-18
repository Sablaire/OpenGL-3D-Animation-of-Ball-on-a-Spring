#include<windows.h>
#include <GL/glut.h>
#include<math.h>
#include<iostream>
#include <stdlib.h>
using namespace std;

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraangle = 30.0;
float i = 0.0, j = 0.0, k = 1.0;

void drawScene()
{
	glClearColor(0.70, 0.70, 0.7, 0.7);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(_cameraangle, 0.0f, 0.0f, 0.0f);
	glTranslatef(0, -2, -20.0f);


#pragma region Table
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glColor3f(0.0, 0.0, 0.4);
	glBegin(GL_QUADS);
	glVertex3f(-23, 0.15, 0);
	glVertex3f(-23, 10, 0);
	glVertex3f(-21, 10, 0);
	glVertex3f(-21, 0.15, 0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-23, -2, 0);
	glVertex3f(-23, 0.15, 0);
	glVertex3f(23, 0.15, 0);
	glVertex3f(23, -2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glLineWidth(8);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-23, -5, 0);
	glVertex3f(-20, -4, 0);
	glVertex3f(-17, -5, 0);
	glVertex3f(-14, -4, 0);
	glVertex3f(-11, -5, 0);
	glVertex3f(-8, -4, 0);
	glVertex3f(-5, -5, 0);
	glVertex3f(-2, -4, 0);
	glVertex3f(1, -5, 0);
	glVertex3f(4, -4, 0);
	glVertex3f(7, -5, 0);
	glVertex3f(10, -4, 0);
	glVertex3f(13, -5, 0);
	glVertex3f(16, -4, 0);
	glVertex3f(19, -5, 0);
	glVertex3f(22, -4, 0);
	glEnd();
	glPopMatrix();

#pragma endregion

#pragma region Line
	glPushMatrix();
	glLineWidth(4);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(-23, 0, 0);
	glVertex3f(-2 + 15 * sin(0.2*i) + cos(0.2*i), 0, -0.02);
	glEnd();
	glPopMatrix();
#pragma endregion

#pragma region Ball
	glPushMatrix();
	glLineWidth(1);
	glTranslatef(15 * sin(0.2*i) + cos(0.2*i), 0, 0);
	glRotatef(_cameraangle, 0.0f, 0.0f, 1.0f);
	glScalef(0.3f, 0.3f, 0.3f);
	glRotatef(_angle, 0.0f, 0.0f, 1.0f);
	glColor3f(1, 1, 0.8);
	glutWireSphere(6, 30, 30);
	glPopMatrix();
#pragma endregion


	i += 0.1*k;
	j += 0.05;
	glutSwapBuffers();
	glutPostRedisplay();
}

void update(int value)
{
	_angle += 2.0f;
	if (_angle>360.f)
	{
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500, 500);
	glutCreateWindow("rotate");
	initRendering();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();

	return 0;
}
