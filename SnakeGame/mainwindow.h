#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

typedef struct _SnakeNode {
    int Id;
    int direction;
    QRect rect;
}SnakeNode;

typedef struct _SnakeList {
    struct _SnakeList* next;
    struct _SnakeList* pre;
    SnakeNode info;
}SnakeList;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionStart_triggered();

private:
    Ui::MainWindow *ui;
    QRect SnakeHeadRDShown();
    void InitNewHead();
    QList<SnakeList*> s_list;
};

#endif // MAINWINDOW_H
