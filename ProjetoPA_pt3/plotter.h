#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "sculptor.h"
class Plotter : public QWidget
{
  Q_OBJECT
private:
  int r, g, b;
  int rd=0, gd=0, bd=0;
  int x,y,z=1;
  int dimX=0, dimY=0, dimZ=0;
  int rX=0, rY=0, rZ=0;
  int radius=0;
  int type=1;
  Sculptor model;
  bool press=false;

public:
  explicit Plotter(QWidget *parent = nullptr);
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  void drawVoxel();
  void eraseVoxel();
  void drawBox();
  void eraseBox();
  void drawEllipsoid();
  void eraseEllipsoid();
  void drawSphere();
  void eraseSphere();
public slots:
  void setXY(int x_, int y_);
  void setZ(int z_);
  void save();
  void setR(int r);
  void setG(int g);
  void setB(int b);
  void setDvoxel();
  void setDbox();
  void setDellipsoid();
  void setDsphere();
  void setEvoxel();
  void setEbox();
  void setEellipsoid();
  void setEsphere();
  void setDimX(int dx);
  void setDimY(int dy);
  void setDimZ(int dz);
  void setRX(int rx);
  void setRY(int ry);
  void setRZ(int rz);
  void setRadius(int r);
  void cleanBoard();

signals:
  void mudaXY(int,int);
};

#endif // PLOTTER_H
