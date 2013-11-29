//--==## Implemented by dr inż. Krzysztof Rojek ##==--

#include "scena.h"

//--==##==--

int FPS;
bool flag=0;
bool i=0;
float delta=1.0f;

Scena::Scena(QApplication* app, QWidget *parent, const char *name)
  : QGLWidget(parent), application(app), tab(new Bazowa*[2])
{  
  tab[0]=new scenapierw();
  tab[1]=new scenadruga();
  

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
    case Qt::Key_Left:
    i=0;
      break;
    case Qt::Key_Right:
    i=1;
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
  tab[i]->paintGL();
}
void Scena::initializeGL()
{
  glClearDepth(1.0f);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glDepthFunc(GL_LEQUAL);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  
  
  glFrontFace(GL_CCW); //punkty Counter Clock Wise
  //glFrontFace(GL_CW); //punkty clock wise
  glEnable(GL_DEPTH_TEST); 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_CULL_FACE);
}

Scena::~Scena()
{
	delete tab[0];
	delete tab[1];
	delete []tab;
}

//--==##==--
