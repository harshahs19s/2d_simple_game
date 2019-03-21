#include "ballthread.h"
#include <QtCore>
ballthread::ballthread(QObject *parent) : QThread(parent)
{
this->stop = false;
}
void ballthread::run()
{
while(1)
{
if(stop)
   break;
emit ballthrough();
this->msleep(10);
}
}
