#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

#define WIDTH 512
#define HEIGTH 256

#define PI 3.14159265
#define PI2 6.283185307

double t = 0;


void init(double theta){
  glBegin(GL_QUADS);
  glVertex2f(-0.5 - 0.5*sin(theta), cos(theta));
  glVertex2f(-0.5 - 0.5*sin(theta + PI/2), cos(theta + PI/2));
  glVertex2f(-0.5 - 0.5*sin(theta + PI), cos(theta + PI));
  glVertex2f(-0.5 - 0.5*sin(theta + 3*PI/2), cos(theta + 3*PI/2));
  glVertex2f(0.5 - 0.5*sin(-theta), cos(-theta));
  glVertex2f(0.5 - 0.5*sin(-theta - PI/2), cos(-theta - PI/2));
  glVertex2f(0.5 - 0.5*sin(-theta - PI), cos(-theta - PI));
  glVertex2f(0.5 - 0.5*sin(-theta - 3*PI/2), cos(-theta - 3*PI/2));
  glEnd();
}

void rotation(){
  t += 0.1;
  if(t >= PI2) t = 0;
  glutTimerFunc(30, rotation, 0);
  glutPostRedisplay();
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);

  init(t);

  glFlush();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitWindowSize(WIDTH, HEIGTH);
  glutCreateWindow("simple");
  glutDisplayFunc(display);
  glutTimerFunc(30, rotation, 0); // physics, movement equations here
  glClearColor(0.0,0.8,0.0,3.0);
  glutMainLoop();
}
