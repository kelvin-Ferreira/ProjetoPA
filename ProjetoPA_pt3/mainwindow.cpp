#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <cmath>
#include <QDebug>
#include <QMouseEvent>
#include <iostream>
#include <QProcess>
#include <qmessagebox.h>
#include <QDialog>
#include <sculptor.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->widget, SIGNAL(mudaXY(int,int)),ui->widget,SLOT(setXY(int,int)));

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setX(int x_)
{
   this -> x=x_;
}

void MainWindow::setY(int y_)
{
    this -> y=y_;
}

void MainWindow::setZ(int z_)
{
    this -> z=z_;
}

int MainWindow::getX()
{
   return x;
}

int MainWindow::getY()
{
    return y;
}

int MainWindow::getZ()
{
    return z;
}

