#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;


int pntX1, pntY1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
vector<int> fixedp;
double angleRad;
float sx,sy;

double round(double d)
{
	return floor(d + 0.5);
}

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

void drawPolygonRotationScaling()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{   
		glVertex2i(round( (( fixedp[0]+ (pntX[i]-fixedp[0]) * cos(angleRad)) - ( (pntY[i] - fixedp[1]) * sin(angleRad)))*sx ), round( ((fixedp[0]+  (pntX[i] - fixedp[0]) * sin(angleRad)) + ( (pntY[i] - fixedp[1]) * cos(angleRad))))*sy );
	}
	glEnd();
}

void myDisplay(void)
{   
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    drawPolygon();
    glFlush();

    while(true)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        cout << "Enter your choice:\n\n" << endl;

        cout << "1. Rotation and scaling" << endl;
        cout << "2. Reflection and shearing" << endl;

        cin >> choice;
        if (choice == 1)
        {
            cout<<" Enter reflection angle \n";
            cin>>angleRad;
            cout<<" Enter the fixed point for rotation \n";
            cin>>pntX1>>pntY1;
            fixedp.push_back(pntX1);
            fixedp.push_back(pntY1);

            cout<<" Enter scaling factors x and y \n";
            cin>>sx>>sy;
        }

        if (choice == 1)
        {
            drawPolygon();
            drawPolygonRotationScaling();
        }

        glFlush();
    }

}

int main(int argc, char** argv)
{

	cout << "\nFor Polygon:" << endl;
	cout << "No of edges: "; cin >> edges;

	for (int i = 0; i < edges; i++)
	{
		cout << "vertex  " << i + 1 << " : "; cin >> pntX1 >> pntY1;
		pntX.push_back(pntX1);
		pntY.push_back(pntY1);
	}

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Extended Basic Transformations");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

}