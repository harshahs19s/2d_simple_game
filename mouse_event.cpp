#include "mouse_event.h"
#include <QMouseEvent>
mouse_event::mouse_event(QWidget *parent):
    QFrame (parent)
{

}

void mouse_event::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pos();
}

void mouse_event::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void mouse_event::leaveEvent(QEvent *)
{
    emit Mouse_Left();
}
