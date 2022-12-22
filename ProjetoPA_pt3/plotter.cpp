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
#include "plotter.h"
#include "sculptor.h"

Plotter::Plotter(QWidget *parent) :
  QWidget(parent){
  r=g=b=245;
  startTimer(10);
  setMouseTracking(true);
}

void Plotter::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  QBrush brush;
  QPen pen;
  int nhoriz=100, nvert=100;

  painter.setRenderHint(QPainter::Antialiasing);

  brush.setColor(QColor(r,g,b));
  brush.setStyle(Qt::SolidPattern);

  painter.setBrush(brush);
  painter.setPen(pen);
  painter.drawRect(0,0,width(), height());

  pen.setColor(QColor(180,180,180));

  pen.setWidth(2);

  painter.setPen(pen);
  for(int i=0; i<nhoriz; i++){
    painter.drawLine(0, i*height()/nhoriz,
                     width(), i*height()/nhoriz);
  }
  for(int i=0; i<nvert; i++){
    painter.drawLine(i*width()/nvert, 0,
                     i*width()/nvert,
                     height());
  }

}


void Plotter::mousePressEvent(QMouseEvent *event)
{
  //qDebug() << event->x() << event->y();

    this->press=true;
    emit mudaXY(event->x(),event->y());
}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    if(this->type==1 && this->press==true){
        emit mudaXY(event->x(),event->y());
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event){
    this->press=false;
}
void Plotter::drawVoxel()
{
    model.setColor((float)rd/255.0,(float)gd/255.0,(float)bd/255.0,1);
    model.putVoxel(x,y,z);
}
void Plotter::drawBox()
{
    model.setColor((float)rd/255.0,(float)gd/255.0,(float)bd/255.0,1);
    model.putBox(x,x+dimX,y,y+dimY,z,z+dimZ);
}

void Plotter::drawEllipsoid()
{
    model.setColor((float)rd/255.0,(float)gd/255.0,(float)bd/255.0,1);
    model.putEllipsoid(x,y,z,rX,rY,rZ);
}
void Plotter::drawSphere()
{
    model.setColor((float)rd/255.0,(float)gd/255.0,(float)bd/255.0,1);
    model.putSphere(x,y,z,radius);
}
void Plotter::eraseVoxel()
{

    model.cutVoxel(x,y,z);
}
void Plotter::eraseBox()
{

    model.cutBox(x,x+dimX,y,y+dimY,z,z+dimZ);
}

void Plotter::eraseEllipsoid()
{

    model.cutEllipsoid(x,y,z,rX,rY,rZ);
}
void Plotter::eraseSphere()
{

    model.cutSphere(x,y,z,radius);
}


void Plotter::setXY(int x_, int y_)
{

   this-> x=(x_*100)/width();
   this-> y=99-((y_*100)/height());

    if(type==1){
       drawVoxel();
    }
    if(type==3){
       drawBox();
    }
    if(type==5){
       drawEllipsoid();
    }
    if(type==7){
       drawSphere();
    }
    if(type==2){
      eraseVoxel();
    }
    if(type==4){
      eraseBox();
    }
    if(type==6){
      eraseEllipsoid();
    }
    if(type==8){
      eraseSphere();
    }
}

void Plotter::setZ(int z_)
{
    this->z = z_;
}

void Plotter::save()
{
    model.writeOFF("modelo2.off");
}

void Plotter::setR(int r)
{
    this-> rd=r;
}
void Plotter::setG(int g)
{
    this-> gd=g;
}
void Plotter::setB(int b)
{
    this-> bd=b;
}

void Plotter::setDvoxel()
{
    this ->type=1;
}

void Plotter::setDbox()
{
    this ->type=3;
}
void Plotter::setDellipsoid()
{
    this ->type=5;
}
void Plotter::setDsphere()
{
    this ->type=7;
}
void Plotter::setEvoxel()
{
    this ->type=2;
}

void Plotter::setEbox()
{
    this ->type=4;
}
void Plotter::setEellipsoid()
{
    this ->type=6;
}
void Plotter::setEsphere()
{
    this ->type=8;
}

void Plotter::setDimX(int dx)
{
    this -> dimX=dx;
}
void Plotter::setDimY(int dy)
{
    this -> dimY=dy;
}
void Plotter::setDimZ(int dz)
{
    this -> dimZ=dz;
}

void Plotter::setRX(int rx)
{
    this ->rX =rx;
}

void Plotter::setRY(int ry)
{
    this ->rY =ry;
}
void Plotter::setRZ(int rz)
{
    this ->rZ =rz;
}

void Plotter::setRadius(int r)
{
    this -> radius = r;
}

void Plotter::cleanBoard()
{
    model.cutBox(0,99,0,99,0,99);
}




