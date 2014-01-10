//--==## Implemented by dr inż. Krzysztof Rojek ##==--

#include "scena.h"

//--==##==--

int FPS;
bool flag=0;
bool i=0;
float delta=1.0f;
GLuint texture[1];
GLuint korka[1];
QImage tex[1],koreczka[1], buf,buf2;
GLUquadric *quadratic;
GLUquadric *quadratic2;


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
  // liscie
  // if(!buf.load("data/lisc.bmp")) { qDebug("Nie znaleziono pliku !"); }
  // else { tex[0] = QGLWidget::convertToGLFormat(buf); }
  // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  // for(int i=0; i<1; ++i)
  //   {
  //     glGenTextures(1, &texture[i]);
  //     glBindTexture(GL_TEXTURE_2D, texture[i]);
  //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex[i].width(), tex[i].height(),
  // 		   0, GL_RGBA, GL_UNSIGNED_BYTE, tex[i].bits());
  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  //   }




  // kora

  // if(!buf.load("data/lisc.bmp")) { qDebug("Nie znaleziono pliku !"); }
  // else { koreczka[0] = QGLWidget::convertToGLFormat(buf2); }
  // glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  // for(int i=0; i<1; ++i)
  //   {
  //     glGenTextures(1, &korka[i]);
  //     glBindTexture(GL_TEXTURE_2D, korka[i]);
  //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, koreczka[i].width(), koreczka[i].height(),
  // 		   0, GL_RGBA, GL_UNSIGNED_BYTE, koreczka[i].bits());
  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  //     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  //   }



  // skala


}

void scenapierw::paintGL()
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
  // gora kwadratu
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

  // prawy scian kwadratu
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
 
  glEnd();
 
  glBegin(GL_QUADS);
  // lewy scian kwadratu
  glColor3f(1.0f, 0.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
 
  glEnd();
 
  glBegin(GL_QUADS);
  // dol kwadratu
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
 
  glEnd();
 
  glBegin(GL_QUADS);
  // tyl kwadratu
  glColor3f(0.0f, 1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);
 
  glEnd();
  // linia
  glLineWidth(0.5f);
  glBegin(GL_LINES);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex3f(0.0f, -5.0f, 0.0f);
  glVertex3f(0.0f, 5.0f, 0.0f);

  glEnd();
  // podloga
  


  glLoadIdentity(); 
  glTranslatef(-5.0f, -4.0f,-20.0f);
  
  for(int i=0; i<10;i++) 
    {
      for(int j=0; j<10;j++)
	{
	  glBegin(GL_TRIANGLES);
	  glColor3f(1.0f, 0.0f, 0.0f);
	  
	  // trojkat lewy podlogi

	  glVertex3f(-0.5f+i, 0.0f, 0.5f+j); 
	  glColor3f(0.3f, 0.25f, 1.0f);
	  glVertex3f(0.5f+i, 0.0f, 0.5f+j);
	  glColor3f(0.21f, 0.40f, 1.0f);
	  glVertex3f(-0.5f+i, 0.0f, -0.5f+j);
	  glEnd();
	  // trojkat prawy podlogi
	  glBegin(GL_TRIANGLES);
	  glColor3f(0.25f, 0.30f, 1.0f);
	  glVertex3f(-0.5f+i, 0.0f, -0.5f+j);
	  glColor3f(1.0f, 0.15f, 0.8f);	  
	  glVertex3f(0.5f+i, 0.0f, 0.5f+j);
	  glColor3f(1.0f, 1.0f, 1.0f);
	  glVertex3f(0.5f+i, 0.0f, -0.5f+j); 
	  glEnd();
	    
	}
    }
}


scenadruga::scenadruga()
{
  
  tablica = new float *[11];
  tablica2 = new float *[11];
  
  for(int i=0; i<11; ++i)
    {
      tablica[i]= new float[11];
      tablica2[i]= new float[11];
      for(int j=0; j<11; ++j)
	{
	  
	  // tablica[i][j] = 0.0f;
	  tablica2[i][j] = (sin(i/3.14f)*cos((j-5.0f)/3.14f)*8.0f);// /200.0f;;
	  
	}
    }

  //--------------
}


scenadruga::~scenadruga()
{
  
  for(int i=0; i<11; ++i)
    {
      delete []tablica[i];
      delete []tablica2[i];
      
    }
  delete []tablica;
  delete []tablica2;
}

void scenadruga::paintGL()
{
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  if(!buf.load("data/rock.bmp")) { qDebug("Nie znaleziono pliku !"); }
  else { tex[0] = QGLWidget::convertToGLFormat(buf); }
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  for(int i=0; i<1; ++i)
    {
      glGenTextures(1, &texture[i]);
      glBindTexture(GL_TEXTURE_2D, texture[i]);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex[i].width(), tex[i].height(),
  		   0, GL_RGBA, GL_UNSIGNED_BYTE, tex[i].bits());
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }
  glEnable(GL_TEXTURE_2D); //142 linia oryginalnie
  glLoadIdentity(); 
  // glRotatef(45.0f, 1.0f, 1.0f, 0.0f); //kąt 45 stopni
  glTranslatef(0.0f, 0.0f,-40.0f);
  static float zz = 0.0f;
  zz+=2.5f*delta;
  glRotatef(zz, 0.0f, 1.0f, 0.0f); // obracanie


  // glLoadIdentity(); 
  glTranslatef(-5.0f, -4.0f,-20.0f);
  
  for(int i=0; i<10.0;i++) 
    {
      for(int j=0; j<10.0;j++)
	{
    	  glBegin(GL_TRIANGLES);


    	  // trojkat lewy podlogi
    	  // glColor3f(1.0f, 1.0f, 1.0f);
	  glTexCoord2f((-0.5f+i)/10, (0.5f+j)/10);
    	  glVertex3f(-0.5f+i, tablica2[i][j+1], 0.5f+j); 
    	  // glColor3f(1.0f, 0.6f, 0.20f);
	  glTexCoord2f((0.5f+i)/10, (0.5f+j)/10);
    	  glVertex3f(0.5f+i, tablica2[i+1][j+1], 0.5f+j);
	  // glColor3f(1.0f, 0.7f, 0.2f);
	  glTexCoord2f((-0.5f+i)/10,(-0.5f+j)/10);
    	  glVertex3f(-0.5f+i, tablica2[i][j], -0.5f+j);
    	  glEnd();




    	  // trojkat prawy podlogi
    	  glBegin(GL_TRIANGLES);
    	  // glColor3f(1.0f, 1.0f, 1.0f);
	  glTexCoord2f((-0.5f+i)/10,(-0.5f+j)/10);
    	  glVertex3f(-0.5f+i, tablica2[i][j], -0.5f+j);	  
    	  // glColor3f(1.0f, 0.33f, 1.0f);
	  glTexCoord2f((0.5f+i)/10,(0.5f+j)/10);
    	  glVertex3f(0.5f+i, tablica2[i+1][j+1], 0.5f+j);
    	  // glColor3f(1.0f, 1.0f, 1.0f);
	  glTexCoord2f((0.5f+i)/10,(-0.5f+j)/10);
    	  glVertex3f(0.5f+i, tablica2[i+1][j], -0.5f+j); 
    	  glEnd();
    	}
    }

  if(!buf.load("data/kora.bmp")) { qDebug("Nie znaleziono pliku !"); }
  else { tex[0] = QGLWidget::convertToGLFormat(buf); }
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  for(int i=0; i<1; ++i)
    {
      glGenTextures(1, &texture[i]);
      glBindTexture(GL_TEXTURE_2D, texture[i]);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex[i].width(), tex[i].height(),
  		   0, GL_RGBA, GL_UNSIGNED_BYTE, tex[i].bits());
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }
  // pierwsze drzewko      
  quadratic = gluNewQuadric();
  gluQuadricTexture(quadratic, GL_TRUE);      // Create Texture Coords
  glRotatef(-90.0f, 90.0f, 1.0f, 0.0f);
  gluCylinder(quadratic,0.3f,0.42f,2.0f,12,12); //wysoosc      

  // drugie drzewo
  glTranslatef(0.0f, 0.0f, 2.0f);
  quadratic = gluNewQuadric();
  gluQuadricTexture(quadratic, GL_TRUE);      // Create Texture Coords
  gluCylinder(quadratic,0.3f,0.42f,2.0f,12,12);      


  // trzecie drzewo
  glTranslatef(0.0f, 0.0f, 2.0f);
  quadratic = gluNewQuadric();
  gluQuadricTexture(quadratic, GL_TRUE);      // Create Texture Coords
  gluCylinder(quadratic,0.3f,0.42f,2.0f,12,12);      


  // glTranslatef(0.0f, 10.0f, 0.0f);


  // quadratic2 = gluNewQuadric();
  // gluQuadricTexture(quadratic2, GL_TRUE);      // Create Texture Coords
  // gluCylinder(quadratic2,0.3f,0.3f,5.0f,12,12);      




  // glTranslatef(-9.0f, 0.0f, 0.0f);


  // quadratic2 = gluNewQuadric();
  // gluQuadricTexture(quadratic2, GL_TRUE);      // Create Texture Coords
  // gluCylinder(quadratic2,0.3f,0.3f,5.0f,12,12);      


  // static int licznik=200;
  // ++licznik;
  // for(int i=0; i<10;++i)
  //   {
  //     for(int j=0; j<10; ++j)
  // 	if(licznik<200)
  // 	  tablica[i][j]+=tablica2[i][j];
  //   }

}



Scena::~Scena()
{
  delete tab[0];
  delete tab[1];
  delete []tab;
}

//--==##==--
