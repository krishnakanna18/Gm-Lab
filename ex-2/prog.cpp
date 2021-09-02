#include<GL/glut.h>
#include<stdio.h>
#include<iostream>

using namespace std;

float x1_arr[8], y1_arr[8], x2_arr[8], y2_arr[8];

void myInit()
{
	glClearColor(0.0,0.0,0.0,1.0);
	gluOrtho2D(-100,100,-100,100);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	float dy,dx,step,x,y,k,Xin,Yin;
	float x1, y1, x2, y2;

	// 1) (10, 10) --> (50, 20)

	for (int i = 0; i < 8; i++) {

		x1 = x1_arr[i];
		y1 = y1_arr[i];
		x2 = x2_arr[i];
		y2 = y2_arr[i];

		dx=x2-x1;
		dy=y2-y1;

		if(abs(dx)> abs(dy))
		{
			step = abs(dx);
		}
		else
			step = abs(dy);

		Xin = dx/step;
		Yin = dy/step;
		// cout << "This is the step: " << step << endl;	

		x= x1;
		y=y1;

		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POINTS);
			glVertex2f(x,y);
		glEnd();

		for (k=1 ;k<=step;k++)
		{
			x= x + Xin;
			y= y + Yin;

			glColor3f(1.0,1.0,1.0);
			glBegin(GL_POINTS);
				glVertex2i(x,y);
			glEnd();
		}

	}

	

	
	
	glFlush();

}

int main(int argc,char* argv[])
{
	// printf("Enter the value of x1 : ");
	// scanf("%f",&x1);
	// printf("Enter the value of y1 : ");
	// scanf("%f",&y1);
	// printf("Enter the value of x2 : ");
	// scanf("%f",&x2);
	// printf("Enter the value of y2 : ");
	// scanf("%f",&y2);

	// x1 = 0.2;
	// y1 = 0.2;
	// x2 = 0.7;
	// y2 = 0.7;

	x1_arr[0] = 10;
	y1_arr[0] = 10;
	x2_arr[0] = 50;
	y2_arr[0] = 20;

	x1_arr[1] = 20;
	y1_arr[1] = 20;
	x2_arr[1] = 30;
	y2_arr[1] = 60;

	x1_arr[2] = -10;
	y1_arr[2] = -10;
	x2_arr[2] = -50;
	y2_arr[2] = -20;

	x1_arr[3] = -20;
	y1_arr[3] = -20;
	x2_arr[3] = -30;
	y2_arr[3] = -60;

	x1_arr[4] = -10;
	y1_arr[4] = 10;
	x2_arr[4] = -50;
	y2_arr[4] = 20;

	x1_arr[5] = -20;
	y1_arr[5] = 20;
	x2_arr[5] = -30;
	y2_arr[5] = 60;

	x1_arr[6] = 10;
	y1_arr[6] = -10;
	x2_arr[6] = 50;
	y2_arr[6] = -20;

	x1_arr[7] = 20;
	y1_arr[7] = -20;
	x2_arr[7] = 30;
	y2_arr[7] = -60;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow("");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 1;
}