#include<GL/glut.h>
void display() {
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
 glColor3f(1.0f,1.0f,1.0f);
 glVertex2i(525,450);
glEnd();
glPointSize(10);
glBegin(GL_LINES);
 glColor3f(0.0,1.0,0.0);
 glVertex2i(500,600);
 glVertex2i(550,600);
 glEnd();
glBegin(GL_LINE_STRIP);
 glColor3f(0.0,0.0,1.0);
 glVertex2i(500,350);
 glVertex2i(525,400);
 glVertex2i(550,350);
 glVertex2i(575,400);
 glVertex2i(600,350);
 glEnd();
glBegin(GL_LINE_LOOP);
 glColor3f(2.0,2.0,1.0);
 glVertex2i(700,350);
 glVertex2i(725,375);
 glVertex2i(700,400);
 glVertex2i(675,375);
 glEnd();
glBegin(GL_TRIANGLES);
 glColor3f(1.0,0.5,0.0);
 glVertex2i(500,650);
 glVertex2i(550,650);
 glVertex2i(525,700);
 glEnd();
glBegin(GL_TRIANGLE_STRIP);
 glColor3f(1.0f, 0.99f, 1.0f);
 glVertex2i(500,800);
 glColor3f(1.0f, 0.99f, 0.0f);
 glVertex2i(550,800);
 glColor3f(0.0f, 0.99f, 1.0f);
 glVertex2i(500,850);
 glColor3f(1.0f, 1.1f, 0.0f);
 glVertex2i(600,850);
 glEnd();

 glBegin(GL_TRIANGLE_FAN);
 glColor3f(1.0f, 0.99f, 0.0f);
 glVertex2i(300,600);
 glVertex2i(350,700);
 glVertex2i(400,650);
 glVertex2i(400,550);
 glVertex2i(350,500);
 glEnd();
 glBegin(GL_QUADS);
 glColor3f(2.0f, 0.0f, 0.0f);
 glVertex2i(500,500);
 glVertex2i(550,500);
 glVertex2i(550,550);
 glVertex2i(500,550);
 glEnd();
 glBegin(GL_QUAD_STRIP);
 glColor3f(2.0f, 2.0f, 2.0f);
 glVertex2i(250,700);
 glVertex2i(250,1000);
 glVertex2i(300,800);
 glVertex2i(300,900);
 glVertex2i(350,800);
 glVertex2i(350,900);
 glVertex2i(400,700);
 glVertex2i(400,1000);
 glEnd();

 glBegin(GL_POLYGON);
 glColor3f(0.5f, 2.0f, 1.0f);
 glVertex2i(650,500);
 glVertex2i(675,450);
 glVertex2i(700,500);
 glVertex2i(700,550);
 glVertex2i(675,600);
 glVertex2i(650,550);
 glEnd();
 glFlush();
}
int main(int argc, char ** argv)
{
 // Initialize GLUT
 glutInit(&argc, argv);
 // Set display mode
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 // Set top - left display window position.
 glutInitWindowPosition(100, 100);
 // Set display window width and height
 glutInitWindowSize(1000,1000);
 // Create display window with the given title
 glutCreateWindow("Exercise 1 Question 1");
 // Execute initialization procedure
 glClearColor(0,0,0,1);
 // Set projection parameters.
 glMatrixMode(GL_PROJECTION);
 // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max
 gluOrtho2D(0.0, 1000, 0.0, 1000);
 // Send graphics to display window
 glutDisplayFunc(display);
 // Display everything and wait.
 glutMainLoop();
}