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


