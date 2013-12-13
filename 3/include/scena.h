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
  scenadruga();
  ~scenadruga();
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
