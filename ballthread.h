#ifndef BALLTHREAD_H
#define BALLTHREAD_H

#include <QObject>
#include <QThread>

class ballthread : public QThread
{
    Q_OBJECT
public:
    explicit ballthread(QObject *parent = nullptr);
    void run();
    bool stop;
signals:
    void ballthrough();

};

#endif // BALLTHREAD_H
