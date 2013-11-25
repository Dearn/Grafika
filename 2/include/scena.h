//--==## Implemented by dr inż. Krzysztof Rojek ##==--

#ifndef SCENA_H
#define SCENA_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <qapplication.h>
#include <qcursor.h>
#include <qgl.h>
#include <qimage.h>
#include <qtimer.h>
#include <sstream>
#include <GL/glu.h>
#include <QKeyEvent>
#include <unistd.h>
//--==##==--

extern bool flag;
extern float delta;

class Bazowa
{
 public:
  virtual void paintGL()=0;
  virtual ~Bazowa(){}
};

class scenapierw:public Bazowa
{
 public:
  void paintGL(){
    
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
  
    for(float i=1.0f; i<10.0;i++) 
      {
	for(float j=1.0f; j<10.0;j++)
	  {
	    glBegin(GL_TRIANGLES);
	    glColor3f(1.0f, 0.0f, 0.0f);
	  
	    // trojkat lewy podlogi

	    glVertex3f(-0.5f+i, 0.0f, 0.5f+j); 
	    glColor3f(0.0f, 0.25f, 1.0f);
	    glVertex3f(0.5f+i, 0.0f, 0.5f+j);
	    glColor3f(1.0f, 1.0f, 1.0f);
	    glVertex3f(-0.5f+i, 0.0f, -0.5f+j);
	    glEnd();
	    // trojkat prawy podlogi
	    glBegin(GL_TRIANGLES);
	    glColor3f(0.25f, 0.30f, 1.0f);
	    glVertex3f(-0.5f+i, 0.0f, -0.5f+j);
	    glColor3f(1.0f, 0.0f, 1.0f);	  
	    glVertex3f(0.5f+i, 0.0f, 0.5f+j);
	    glColor3f(1.0f, 1.0f, 1.0f);
	    glVertex3f(0.5f+i, 0.0f, -0.5f+j); 
	    glEnd();
	    
	  }
      }
		
		
  }
};

class scenadruga:public Bazowa
{
 public:
  void paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
  }
};



class Scena : public QGLWidget
{
  Q_OBJECT
 private:
  QApplication *application;
  Bazowa **tab;
      

 public:
  Scena(QApplication* app, QWidget *parent=NULL, const char *name=NULL);

  void initializeGL();
  void resizeGL(int w, int h);
  void paintGL();

  void keyPressEvent(QKeyEvent *e);
  void keyReleaseEvent(QKeyEvent *e);

  ~Scena();

  private slots:
    void timerGL();
    void timerFPS();
};

//--==##==--

#endif
