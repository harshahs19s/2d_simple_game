#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include <QWidget>
#include <QFrame>

class mouse_event : public QFrame
{

        Q_OBJECT
public:
    explicit mouse_event(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *);

    int x,y;

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();

public slots:
};


#endif // MOUSE_EVENT_H
