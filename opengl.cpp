#include<iostream>
#include<gl/glut.h>
#include <vector>
#include "general.h"
using namespace std;

vector<XYZ> points;
void readDataToVector(string filename)
{
	FILE *fis = fopen(filename.c_str(), "r");
	if (fis)
	{
		while (!feof(fis))
		{
			XYZ xyz;
			fscanf(fis, "%lf, %lf, %lf", &xyz.x, &xyz.y, &xyz.z);
			points.push_back(xyz);
		}
	}
	fclose(fis);
}
void disPlay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotated(45, 0, 0, 1.0);
	glRotated(45, -1.0, 0, 0);
	glRotated(45, 0, 1.0, 0);
	//glOrtho(5.0, 5.0, 5.0, 5.0, 5.0, 5.0);
	//glScaled(1.2, 1.2, 1.2);
	for (int i = 0; i < points.size();)
	{
		XYZ pt1 = points[i++], pt2 = points[i++], pt3 = points[i++];
		glBegin(GL_TRIANGLES);
		glVertex3d(pt1.x, pt1.y, pt1.z);
		glVertex3d(pt2.x, pt2.y, pt2.z);
		glVertex3d(pt3.x, pt3.y, pt3.z);
		glEnd();
	}
	
	glFlush();
}
void glDisPlay(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("第一个OpenGL程序");
	glutDisplayFunc(&disPlay);
	glutMainLoop();
}

int main(int argc, char *argv[])
{
	readDataToVector("f:/data/three.txt");
	glDisPlay(argc, argv);
	system("pause");
	return 0;
}