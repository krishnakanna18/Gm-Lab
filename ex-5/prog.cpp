#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
int transX, transY;
double scaleX, scaleY;
double angle, angleRad;
char reflectionAxis, shearingAxis;
int shearingX, shearingY;

double round(double d)
{
	return floor(d + 0.5);
}

void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}


void drawPolygonTrans(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntX[i] + x, pntY[i] + y);
	}
	glEnd();
}

void drawPolygonScale(double x, double y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
	}
	glEnd();
}

void drawPolygonRotation(double angleRad)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
	}
	glEnd();
}

void drawLine()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}


void drawLineTrans(int x, int y)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(pntX[i] + x, pntY[i] + y);
	}
	glEnd();
}

void drawLineScale(double x, double y)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
	}
	glEnd();
}

void drawLineRotation(double angleRad)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < edges; i++)
	{
		glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
	}
	glEnd();
}


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	if (choice == 1)
	{
		drawPolygon();
		drawPolygonTrans(transX, transY);
	}
	else if (choice == 2)
	{
		drawPolygon();
		drawPolygonScale(scaleX, scaleY);
	}
	else if (choice == 3)
	{
		drawPolygon();
		drawPolygonRotation(angleRad);
	}
    	if (choice == 4)
	{
		drawLine();
		drawLineTrans(transX, transY);
	}
	else if (choice == 5)
	{
		drawLine();
		drawLineScale(scaleX, scaleY);
	}
	else if (choice == 6)
	{
		drawLine();
		drawLineRotation(angleRad);
	}

	glFlush();
}

int main(int argc, char** argv)
{   

    char ch;
    // do
    // {

        /* code */
        cout << "Enter your choice:\n\n" << endl;

        cout << "1. Translation for polygon" << endl;
        cout << "2. Scaling for polygon" << endl;
        cout << "3. Rotation for polygon" << endl;
        cout << "4. Translation for Line "<<endl;
        cout << "5. Scaling for Line" << endl;
        cout << "6. Rotation for Line" << endl;

        cin >> choice;

        if(choice==1 || choice==2 || choice==3)
        {
            cout << "Enter no of edges: "; cin >> edges;
        }
        else
            edges=2;
        

        for (int i = 0; i < edges; i++)
        {
            cout << "Enter co-ordinates for vertex  " << i + 1 << " : "; cin >> pntX1 >> pntY1;
            pntX.push_back(pntX1);
            pntY.push_back(pntY1);
        }

        if (choice == 1)
        {
            cout << "Enter the translation factor for X and Y: "; cin >> transX >> transY;
        }
        else if (choice == 2)
        {
            cout << "Enter the scaling factor for X and Y: "; cin >> scaleX >> scaleY;
        }
        else if (choice == 3)
        {
            cout << "Enter the angle for rotation: "; cin >> angle;
            angleRad = angle * 3.1416 / 180;
        }
        else if (choice == 4)
        {
            cout << "Enter the translation factor for X and Y: "; cin >> transX >> transY;
        }
        else if (choice == 5)
        {
            cout << "Enter the scaling factor for X and Y: "; cin >> scaleX >> scaleY;
        }
        else if (choice == 6)
        {
            cout << "Enter the angle for rotation: "; cin >> angle;
            angleRad = angle * 3.1416 / 180;
        }

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(640, 480);
        glutInitWindowPosition(100, 150);
        glutCreateWindow("Ex 5");
        glutDisplayFunc(myDisplay);
        myInit();
        glutMainLoop();

        cout<<"Do you want to continue(y/n)?";
        cin>>ch;
        
    // }while(ch=='y');


}