#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "plotter.h"
#include "sculptor.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
