#include <GL/glut.h>
void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0); // Set line color to white
  glBegin(GL_LINES);
  glVertex2f(-0.5, -0.5); // First line segment
  glVertex2f(0.5, 0.5);
  glVertex2f(0.5, -0.5); // Second line segment
  glVertex2f(-0.5, 0.5);
  glEnd();
  glFlush();
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Creating lines in OpenGL");
  glutInitWindowSize(320, 320);
  glutInitWindowPosition(50, 50);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
