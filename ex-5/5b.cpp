#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
//int transX, transY;
//double scaleX, scaleY;
//double angle, angleRad;
char reflectionAxis, shearingAxis;
int shearingX, shearingY;

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



void drawPolygonMirrorReflection(char reflectionAxis)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);

	if (reflectionAxis == 'x' || reflectionAxis == 'X')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(pntX[i]), round(pntY[i] * -1));

		}
	}
	else if (reflectionAxis == 'y' || reflectionAxis == 'Y')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(pntX[i] * -1), round(pntY[i]));
		}
	}
	else if(reflectionAxis == 'o' || reflectionAxis =='O')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(pntX[i] * -1), round(pntY[i]* -1));
		}
	}
	else if(reflectionAxis == 's' || reflectionAxis =='S')
	{
		for (int i = 0; i < edges; i++)
		{
			glVertex2i(round(pntY[i]* 1 ), round(pntX[i] *1 ));
		}
	}


	glEnd();
}

void drawPolygonShearing()
{
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 1.0);

	if (shearingAxis == 'x' || shearingAxis == 'X')
	{
		glVertex2i(pntX[0], pntY[0]);

		glVertex2i(pntX[1] + shearingX, pntY[1]);
		glVertex2i(pntX[2] + shearingX, pntY[2]);

		glVertex2i(pntX[3], pntY[3]);
	}
	else if (shearingAxis == 'y' || shearingAxis == 'Y')
	{
		glVertex2i(pntX[0], pntY[0]);
		glVertex2i(pntX[1], pntY[1]);
		
		glVertex2i(pntX[2], pntY[2] + shearingY);
		glVertex2i(pntX[3], pntY[3] + shearingY);
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

        cout << "1. Mirror Reflection" << endl;
        cout << "2. Shearing" << endl;

	    cin >> choice;
        if (choice == 1)
        {
            cout << "Reflection axis ( x or y or o or s ): "; cin >> reflectionAxis;
        }
        else if (choice == 2)
        {
            cout << "Axis (x or y)  "; cin >> shearingAxis;
            if (shearingAxis == 'x' || shearingAxis == 'X')
            {
                cout << "shearing factor for X: "; cin >> shearingX;
            }
            else
            {
                cout << "shearing factor for Y: "; cin >> shearingY;
            }
        }

        if (choice == 1)
        {
            drawPolygon();
            drawPolygonMirrorReflection(reflectionAxis);
        }
        else if (choice == 2)
        {
            drawPolygon();
            drawPolygonShearing();
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
    
    
	return 0;
}