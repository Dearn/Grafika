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

class Scena : public QGLWidget
{
   Q_OBJECT
   private:
      QApplication *application;
      bool flag;
      float delta; /* = 1.0f; */

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
