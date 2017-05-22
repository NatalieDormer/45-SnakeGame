#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "time.h"
#include "stdlib.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_actionStart_triggered()
{
    InitNewHead();

}




void MainWindow::InitNewHead()
{
    QRect rec = SnakeHeadRDShown();
    s_list.clear();//list init

    SnakeList* node = new SnakeList();
    node->next = NULL;
    node->pre = NULL;
    node->info.direction = Qt::Key_Left;
    node->info.Id = 1;
    node->info.rect = rec;
    s_list.append(node);
}










QRect MainWindow::SnakeHeadRDShown()
{
    QRect rec = ui->moveRange->geometry();
    QRect range_head = ui->rdHead->geometry();
    QRect range_move;//snake head move range
    range_move.setX(rec.x());
    range_move.setY(rec.y());
    range_move.setWidth(rec.width() - range_head.width());
    range_move.setHeight(rec.height() - range_head.height());

    //random x1,y1
    time_t t;
    srand((unsigned) time(&t));
    int rx = rand()%(range_move.width() - range_move.x() + 1) + range_move.x();
    int ry = rand()%(range_move.height() - range_move.y() + 1) + range_move.y();

    ui->rdHead->setGeometry(QRect(rx, ry, range_head.width(), range_head.height()));

    return ui->rdHead->geometry();
}
