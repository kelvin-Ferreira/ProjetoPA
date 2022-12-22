#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "sculptor.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int x,y,z;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setX(int x_);
    void setY(int y_);
    void setZ(int z_);

public:
    int getX();
    int getY();
    int getZ();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
