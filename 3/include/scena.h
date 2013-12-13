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

class scenapierw: public Bazowa
{
 public:
  void paintGL();
    
    
};

class scenadruga: public Bazowa
{
 private:
  float **tablica;
  float **tablica2;
 public:
  void paintGL();
  
  scenadruga() // zaj. 13.12.13
    {
      tablica = new float *[11];
      tablica2 = new float *[11];

      for(int i=0; i<11; ++i)
      	{
      	  tablica[i]= new float[11];
      	  tablica2[i]= new float[11];
	  for(int j=0; j<11; ++j)
	    {
	      
	      tablica[i][j] = 0.0f;
	      tablica2[i][j] = (sin(i/3.14f)*cos((j-5.0f)/3.14f)*8.0f)/200.0f;

	    }
      	}
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
