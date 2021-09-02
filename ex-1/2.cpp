#include<GL/glut.h>
void display() {
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_QUADS);
 glColor3f(1.0f, 0.5f, 0.5f);
 glVertex2i(300,300);
 glVertex2i(600,300);
 glVertex2i(600,600);
 glVertex2i(300,600);
 glEnd();
 
glBegin(GL_QUADS);
 glColor3f(0.1f, 0.4f, 0.0f);
 glVertex2i(400,300);
 glVertex2i(500,300);
 glVertex2i(500,500);
 glVertex2i(400,500);
 glEnd();

 glBegin(GL_POINTS);
 glColor3f(1.0f,1.0f,1.0f);
 glVertex2i(410,400);
glEnd();
glPointSize(10);

 glBegin(GL_QUADS);
 glColor3f(2.0f,0.5f,0.5f);
 glVertex2i(325,450);
 glVertex2i(375,450);
 glVertex2i(375,500);
 glVertex2i(325,500);
 glEnd();
glBegin(GL_LINES);
 glColor3f(0.1,0.1,0.1);
 glVertex2i(350,450);
 glVertex2i(350,500);
 glEnd();
glBegin(GL_LINES);
 glColor3f(0.1,0.1,0.1);
 glVertex2i(325,475);
 glVertex2i(375,475);
 glEnd();

 glBegin(GL_QUADS);
 glColor3f(2.0f,0.5f,0.5f);
 glVertex2i(525,450);
 glVertex2i(575,450);
 glVertex2i(575,500);
 glVertex2i(525,500);
 glEnd();
glBegin(GL_LINES);
 glColor3f(0.1,0.1,0.1);
 glVertex2i(550,450);
 glVertex2i(550,500);
 glEnd();
glBegin(GL_LINES);
 glColor3f(0.1,0.1,0.1);
 glVertex2i(525,475);
 glVertex2i(575,475);
 glEnd();

glBegin(GL_QUADS);
 glColor3f(0.5f, 0.5f, 0.5f);
 glVertex2i(275,600);
 glVertex2i(625,600);
 glVertex2i(625,625);
 glVertex2i(275,625);
 glEnd();
glBegin(GL_POLYGON);
 glColor3f(3.0f, 0.1f, 0.5f);
 glVertex2i(225,625);
 glVertex2i(675,625);
 glVertex2i(600,700);
 glVertex2i(300,700);
 glEnd();

 glBegin(GL_QUADS);
 glColor3f(1.0f, 1.0f, 0.5f);
 glVertex2i(525,700);
 glVertex2i(575,700);
 glVertex2i(575,770);
 glVertex2i(525,770);
 glEnd();
glBegin(GL_QUADS);
 glColor3f(0.5f, 0.5f, 0.5f);
 glVertex2i(515,770);
 glVertex2i(585,770);
 glVertex2i(585,795);
 glVertex2i(515,795);
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
 glutCreateWindow("House Design");
 // Execute initialization procedure
 glClearColor(0.3,0.5,1,1);
 // Set projection parameters.
 glMatrixMode(GL_PROJECTION);
 // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max
 gluOrtho2D(0.0, 1000, 0.0, 1000);
 // Send graphics to display window
 glutDisplayFunc(display);
 // Display everything and wait.
 glutMainLoop();
}