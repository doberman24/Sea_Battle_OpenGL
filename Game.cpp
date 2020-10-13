#include <GL/freeglut.h>
#include <vector>
#include "Field.h"
#include "Marker.h"

int WField = 300;
int HField = 300;
int StField = 30;
int FField = 60;
bool pushL = false, pushR = false;
float X = 0.0, Y = 0.0;
int n = 0;

std::vector<Cell> Tp;
std::vector<Cell> Tp1;

void display()
{
  Field field1(WField, HField, StField, FField, FField);
  Field field2(WField, HField, StField, FField * 3 + WField, FField);
  std::vector<Marker> M;

  glClear(GL_COLOR_BUFFER_BIT);

  for (int i = 0; i < (WField * 2 + 2 * FField) / StField; ++i)
  {
    Marker *coord = new Marker(i, FField, StField);
    M.push_back(*coord);
  }

  field1.DisplayField();
  field2.DisplayField();

  Cell *square1;
  Cell *square2;
  Cell *square3;
  if (pushL && (X > FField) && (X < (FField + WField)) &&
      (Y > FField) && (Y < (FField + HField)))
  {
    square1 = new Cell(X, Y, 1, 0.0, 1.0, 0.0);
    Tp.push_back(*square1);
  }
  else if (pushL && (X > (FField * 3 + WField)) && 
	   (X < (FField * 3 + 2 * WField)) &&
	   (Y > FField) && (Y < (FField + HField)))
  {
    square3 = new Cell(X - 2 * FField - WField, Y, 2, 1.0, 1.0, 0.0);
    Tp1.push_back(*square3);
    for (int i = 0; i < Tp1.size(); ++i)
      for (int j = i; j < Tp.size(); ++j)
      {
	if (Tp[i].x == Tp1[j].x)
	{
	  square2 = new Cell(X, Y, 2, 1.0, 0.0, 0.0);
	  break;
	}
	else
	  square2 = new Cell(X, Y, 2, 1.0, 1.0, 0.0);
      }
    Tp.push_back(*square2);
  }
  glBegin(GL_QUADS);
  for (std::vector<Cell>::iterator i = Tp.begin(); i != Tp.end(); ++i)
  {
    for (std::vector<Marker>::iterator k = M.begin(); k != M.end(); ++k)
      if((i->x - 15) <= k->x)
      {
	i->x = k->x;
	break;
      }
    for (std::vector<Marker>::iterator k = M.begin(); k != M.end(); ++k)
      if((i->y - 15) <= k->y)
      {
	i->y = k->y;
	break;
      }
    i->Draw();
  }
  if (pushR)
  {
    for (std::vector<Cell>::iterator i = Tp.end(); i != Tp.begin(); --i)
    {
      Tp.erase(i);
      break;
    }
  }
  


  glEnd();
  glFlush();
}

void Timer(int)
{
  glutPostRedisplay();
  glutTimerFunc(10, Timer, 0);
  }

void MousePush(int button, int state, int ax, int ay)
{  
  pushL = button == GLUT_LEFT_BUTTON && state == GLUT_DOWN;
  pushR = button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN;
  X = ax;
  Y = ay;
}

void Initialize()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 840, 420, 0, -200, 200);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(840, 420);
  glutInitWindowPosition(200, 150);
  glutCreateWindow("OpenGL");
  Initialize();
  glutDisplayFunc(display);
  glutTimerFunc(10, Timer, 0);
  glutMouseFunc(MousePush);
  //Зацикливаем OpenGL
  glutMainLoop();
  return 0;
}
