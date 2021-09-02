#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

float x1,x2,y1,y2,m;

void display(void)
{
	for(int i=0;i<700;i++)
	{
	float dy,dx,step,x,y,xinc,yinc;
	step = rand()%30;
	xinc = 1;
	yinc = 1;
	x= (rand() % (200)) - 100;
	y= (rand() % (200)) - 100;
	glBegin(GL_POINTS);
	glColor3ub(100,100,255);
	for (int k=0;k<=step;k++)
	{
		glVertex2i(x,y);
		x += xinc;
		y += yinc;
	}
	glEnd();
	}
	glFlush();
}
 
void init(void)
{
glClearColor(1.0,1.0,1.0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}
 
int main(int argc, char** argv) {
srand(time(0));
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (800,800);
glutInitWindowPosition (0,0);
glutCreateWindow ("Rain Pattern DDA");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}