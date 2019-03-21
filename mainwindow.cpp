#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <ballthread.h>
#include <QtCore>
#include <QtDebug>
#include <mouse_event.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1051,550);
    ui->game_over->hide();
    init();
    reset();
    ui->label_2->setNum(score);
    connect(ui->user_bat,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_current_pos()));
    connect(ui->user_bat,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_pressed()));
    connect(ui->user_bat,SIGNAL(Mouse_Left()),this,SLOT(Mouse_left()));

   random_no=0;
   timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(timer_event()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{



}

void MainWindow::on_pushButton_clicked()
{
   ba  = new ballthread(this);
    reset();
    connect(ba,SIGNAL(ballthrough()),this,SLOT(draw()));
    ui->game_over->hide();
    ba->start();
    timer->start(120000);


}


void MainWindow::draw()
{

  // qDebug()<<"RANDUM_NO"<<qrand()%10;
  ui->ball->setGeometry(x, y, 42, 42);
  x = x + move_x;
  y = y + move_y;

  if(x > boundry_width)
  {
    x = boundry_width;
    move_x = -move_x;
    if(random_no < (qrand()%10))
    {
    system_bat_move();
    random_no++;
    }
    else {
    sys_score++;
    system_bat_move_wrong();
    ui->label->setNum(sys_score);
    init();

    }

  }
  if(y > boundry_height) {
    y = boundry_height;
    move_y = -move_y;
  }
  if(x < 0) {
    x = 0;
    move_x = -move_x;
    if((ui->user_bat->y) <= y && (ui->user_bat->y+180) >= y)
    {
      qDebug()<<"hit"<<ui->user_bat->y;
      qDebug()<<"hit"<<y;
    }
    else {
       score++;
      qDebug()<<"left"<<ui->user_bat->y;
      qDebug()<<"left"<<y;
      ui->label_2->setNum(score);
      init();


    }

  }
  if(y < 0) {
    y = 0;
    move_y = -move_y;

  }
}

void MainWindow::on_pushButton_2_clicked()
{
    ba->stop = true;
}

void MainWindow::system_bat_move()
{
 sb_y=y-100;
 ui->system_bat->setGeometry(1010,sb_y,41,191);

}

void MainWindow::system_bat_move_wrong()
{
    sb_y=y+100;
    ui->system_bat->setGeometry(1010,sb_y,41,191);

}

void MainWindow::Mouse_pressed()
{

}

void MainWindow::Mouse_current_pos()
{

    ui->user_bat->setGeometry(0,(ui->user_bat->y)*0.95,41,191);
}

void MainWindow::Mouse_left()
{

}

void MainWindow::init()
{

    right_flag=0;
    left_flag=0;
    ch=0;
    y=300;
    x=980;
    boundry_width = 1000;
    boundry_height = 500;
    move_x=3;
    move_y=-1;
    sb_y=180;
    random_no=0;

}

void MainWindow::timer_event()
{

    ui->game_over->show();
    ba->stop = true;
    init();


}

void MainWindow::reset()
{
    score = 0;
    sys_score=0;
    ui->label_2->setNum(0);
    ui->label->setNum(0);
}


