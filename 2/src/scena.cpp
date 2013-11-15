//--==## Implemented by dr inż. Krzysztof Rojek ##==--

#include "scena.h"

//--==##==--

int FPS;

Scena::Scena(QApplication* app, QWidget *parent, const char *name)
  : QGLWidget(parent), application(app)
{
  setMinimumSize(640, 480);
  setMaximumSize(1980, 1050);
  
  setMouseTracking(true);
  QCursor::setPos(10, 10);
  setCursor(QCursor(Qt::BlankCursor));
  flag = 0;
  
}

void Scena::timerFPS()
{
  std::cout << "FPS: " << FPS << '\n';
  delta=50.0f/FPS;
  FPS=0;
}

void Scena::AnimacjaStop()
{



}

void Scena::timerGL()
{
  updateGL();
  ++FPS;

}

void Scena::keyPressEvent(QKeyEvent *e)
{
  switch( e->key() )
    {
    case Qt::Key_Escape:
      application->quit();
      break;
    case Qt::Key_Space:
      flag = !flag;
      break;
    }
}


void Scena::keyReleaseEvent(QKeyEvent *e)
{
}

void Scena::resizeGL(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, (float)w/(float)h, 1.0f, 100.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Scena::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
   
  //--==## start from here ##==--
  if(flag) // 25fps
    {
      usleep(40000);
    }

   
  glTranslatef(0.0f, 0.0f,-10.0f);
  static float z = 0.0f;
  z+=2.5f*delta;
  glRotatef(45.0f, 1.0f, 1.0f, 0.0f); //kąt 45 stopni
  glRotatef(z, 0.0f, 1.0f, 0.0f); // obracanie



  glBegin(GL_QUADS);
  // top
  glColor3f(1.0f, 0.0f, 0.0f);   
  glVertex3f(-1.0f, 1.0f, 1.0f); 
  glVertex3f(1.0f, 1.0f, 1.0f);  
  glVertex3f(1.0f, 1.0f, -1.0f); 
  glVertex3f(-1.0f, 1.0f, -1.0f);
 
  glEnd();
 
  glBegin(GL_QUADS);


 
  // glEnd();
  glColor3f(0.0f, 1.0f, 0.0f);
 
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
 
  glEnd();
 
  glBegin(GL_QUADS);

  // right
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
 
  glEnd();
 
  glBegin(GL_QUADS);
  // left
  glColor3f(1.0f, 0.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
 
  glEnd();
 
  glBegin(GL_QUADS);
  // bottom
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
 
  glEnd();
 
  glBegin(GL_QUADS);
  // back
  glColor3f(0.0f, 1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
 
  glEnd();
    // line
  glLineWidth(0.5f);
  glBegin(GL_LINES);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex3f(0.0f, -5.0f, 0.0f);
  glVertex3f(0.0f, 5.0f, 0.0f);

  glEnd();
  // podloga
  


  glLoadIdentity(); // zresetowanie translate/rotate
  glTranslatef(-5.0f, -4.0f,-20.0f);
  
  for(float i=1.0f; i<10.0;i++) 
    {
      for(float j=1.0f; j<10.0;j++)
	{
	  glBegin(GL_TRIANGLES);
	  glColor3f(1.0f, 0.0f, 0.0f);
	  
	  // lewy trojkat
	  glVertex3f(-0.5f+i, 0.0f, 0.5f+j); 
	  glColor3f(0.65f, 1.0f, 0.0f);
	  glVertex3f(0.5f+i, 0.0f, 0.5f+j);
	  glColor3f(0.72f, 0.0f, 0.43f);
	  glVertex3f(-0.5f+i, 0.0f, -0.5f+j);
	  glEnd();
	  // prawy trojkat
	  glBegin(GL_TRIANGLES);
	  glColor3f(0.330f, 0.0f, 1.0f);
	  glVertex3f(-0.5f+i, 0.0f, -0.5f+j);
	  glColor3f(0.210f, 1.0f, 0.0f);	  
	  glVertex3f(0.5f+i, 0.0f, 0.5f+j);
	  glColor3f(0.354f, 0.0f, 0.0f);
	  glVertex3f(0.5f+i, 0.0f, -0.5f+j); 
	  glEnd();
	    
	}
    }
  
}
void Scena::initializeGL()
{
  glClearDepth(1.0f);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glDepthFunc(GL_LEQUAL);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  // laboratorium 2
 
  glFrontFace(GL_CCW);
  glEnable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_CULL_FACE);
}

Scena::~Scena()
{
}

//--==##==--
