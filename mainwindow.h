#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <ballthread.h>
#include <QMainWindow>
#include <QRandomGenerator>
#include <QTimerEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int x;
    int y;
    int boundry_width;
    int boundry_height;

     ballthread *ba;

     int right_flag;
     int left_flag;
     int ch;
     int move_x;
     int move_y;
     int sb_y;
     int score;
     int random_no;
     QRandomGenerator randum;
     int sys_score;

     int timer_id;

     QTimer *timer;

private slots:
    void on_pushButton_pressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void draw();

public slots:


    void system_bat_move();

    void system_bat_move_wrong();

    void Mouse_pressed();

    void Mouse_current_pos();

    void Mouse_left();

    void init();

    void timer_event();

    void reset();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
