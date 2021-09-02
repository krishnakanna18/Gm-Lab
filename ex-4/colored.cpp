#include<GL/glut.h>
#include<iostream>
using namespace std;

int R, X, Y;
void pointplot(int x, int y)
{
    glBegin(GL_POINTS);
	glColor3f(0.35f, 0.35f, 0.05f);
	glVertex2i(x+X, y+Y);
	glPointSize(15);
	glEnd();
}

void circles(int R1,int R)
{
	while(R1 > R)
	{
    int x=0, y=R1;
    int p=5/4-R1;
    while(x<y)
    {
        x++;
        if(p<=0)
        {
            p += 2*(x+1) + 1;
        }
        else
        {
            y--;
            p += 2*(x+1) - 2*(y-1) + 1;
        }
        
        pointplot(x, y);
        pointplot(x, -y);
        pointplot(-x, y);
        pointplot(-x, -y);
        pointplot(y, x);
        pointplot(y, -x);
        pointplot(-y, x);
        pointplot(-y, -x);
    }
    
    glFlush();
    R1 -=0.01;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int R1 = R+20;
	circles(R1,R);
	circles(20,0);
	glBegin(GL_LINES);
		glVertex2f(0,20);
		glVertex2f(0,100);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0,0);
		glVertex2f(85,85);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0,0);
		glVertex2f(-85,85);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0,0);
		glVertex2f(-85,-85);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0,0);
		glVertex2f(85,-85);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(20,0);
		glVertex2f(100,0);
	glEnd();
	
	glBegin(GL_LINES);
		glVertex2f(-20,0);
		glVertex2f(-100,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(0,-20);
		glVertex2f(0,-100);
	glEnd();
	glFlush();
	
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(700, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("EX4-Circle-Midpt");
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-250, 250, -250, 250);
	X = 0;
	Y = 0;
	R = 100;
    glutDisplayFunc(display);
	glutMainLoop();
}












