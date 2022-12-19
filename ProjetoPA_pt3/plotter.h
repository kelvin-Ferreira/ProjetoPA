#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget
{
  Q_OBJECT
private:
  float A, freq, teta, veloc;
  int r, g, b;

};

#endif // PLOTTER_H
