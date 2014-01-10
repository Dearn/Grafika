//--==## Implemented by dr inż. Krzysztof Rojek ##==--

#include "scena.h"

//--==##==--

int main(int argc, char** argv)
{
   std::cout << "Start\n";
     
   QApplication Application(argc, argv);

   if (!QGLFormat::hasOpenGL())
   {
      qWarning("Ten system nie wspiera biblioteki OpenGL!");
      return -1;
   }

   Scena scena(&Application);
   //Application.setMainWidget(&scena);
   scena.show();

   QTimer *timerGL = new QTimer(&scena);
   QObject::connect(timerGL, SIGNAL(timeout()), &scena, SLOT(timerGL()));
   timerGL->start(20);

   QTimer *timerFPS = new QTimer(&scena);
   QObject::connect(timerFPS, SIGNAL(timeout()), &scena, SLOT(timerFPS()));
   timerFPS->start(1000);

   int ret=Application.exec();

   delete timerGL;
   delete timerFPS;

   std::cout << "Stop\n";

   return ret;
}

//--==##==--
