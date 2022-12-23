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
  int m[100][100][100];
  int dx,dy;

public:
  /*!Construtor padrão da classe: Cria a ferramenta de desenho.*/
  explicit Plotter(QWidget *parent = nullptr);
  /*!Cria o grid da ferramenta.*/
  void paintEvent(QPaintEvent *event);
  /*!envia o sinal para o programa sempre que o botão esquerdo do mouse
    é precionado, emitindo suas coordenadas em x e y.*/
  void mousePressEvent(QMouseEvent *event);
  /*!envia o sinal para o programa enqunto o mouse deslisa pela ferramenta
    de desenho, emitindo suas coordenadas em x e y.*/
  void mouseMoveEvent(QMouseEvent *event);
  /*!envia o sinal para o programa sempre que o botão esquerdo do mouse
    é solto apos ser precionado.*/
  void mouseReleaseEvent(QMouseEvent *event);
  /*!Desenha um voxel no arquivo .off a partir da ferramenta de desenho.*/
  void drawVoxel();
  /*!Apaga um voxel no arquivo .off a partir da ferramenta de desenho.*/
  void eraseVoxel();
  /*!Desenha uma caixa no arquivo .off a partir da ferramenta de desenho.*/
  void drawBox();
  /*!Apaga uma caixa no arquivo .off a partir da ferramenta de desenho.*/
  void eraseBox();
  /*!Desenha um ellipsoide no arquivo .off a partir da ferramenta de desenho.*/
  void drawEllipsoid();
  /*!Apaga um ellipsoide no arquivo .off a partir da ferramenta de desenho.*/
  void eraseEllipsoid();
  /*!Desenha uma esfera no arquivo .off a partir da ferramenta de desenho.*/
  void drawSphere();
  /*!Apaga uma esfera no arquivo .off a partir da ferramenta de desenho.*/
  void eraseSphere();
public slots:
  /*!Recebe as coordenadas do mouse ao clique.*/
  void setXY(int x_, int y_);
  /*!Recebe o valor da coordenada Z a partir de um slider.*/
  void setZ(int z_);
  /*!Salva o desenho num arquivo .off ao clique num botão.*/
  void save();
  /*!Recebe o valor da palheta de cor R a partir de um slider.*/
  void setR(int r);
  /*!Recebe o valor da palheta de cor G a partir de um slider.*/
  void setG(int g);
  /*!Recebe o valor da palheta de cor B a partir de um slider.*/
  void setB(int b);
  /*!Seleciona o desenho de um voxel ao receber o sinal de um botão.*/
  void setDvoxel();
  /*!Seleciona o desenho de uma caixa ao receber o sinal de um botão.*/
  void setDbox();
  /*!Seleciona o desenho de um ellipisoide ao receber o sinal de um botão.*/
  void setDellipsoid();
  /*!Seleciona o desenho de uma esfera ao receber o sinal de um botão.*/
  void setDsphere();
  /*!Seleciona o apagar de um voxel ao receber o sinal de um botão.*/
  void setEvoxel();
  /*!Seleciona o apagar de uma caixa ao receber o sinal de um botão.*/
  void setEbox();
  /*!Seleciona o apagar de um ellipisoide ao receber o sinal de um botão.*/
  void setEellipsoid();
  /*!Seleciona o apagar de uma esfera ao receber o sinal de um botão.*/
  void setEsphere();
  /*!Recebe o valor da dimenção X duma caixa a partir de um slider.*/
  void setDimX(int dx);
  /*!Recebe o valor da dimenção Y duma caixa a partir de um slider.*/
  void setDimY(int dy);
  /*!Recebe o valor da dimenção Z duma caixa a partir de um slider.*/
  void setDimZ(int dz);
  /*!Recebe o valor do raio do eixo X dum ellipisoide a partir de um slider.*/
  void setRX(int rx);
  /*!Recebe o valor do raio do eixo Y dum ellipisoide a partir de um slider.*/
  void setRY(int ry);
  /*!Recebe o valor do raio do eixo Z dum ellipisoide a partir de um slider.*/
  void setRZ(int rz);
  /*!Recebe o valor do raio duma esfera a partir de um slider.*/
  void setRadius(int r);
  /*!Apaga do desenho.*/
  void cleanBoard();

signals:
  /*!Envia como sinal as coordenadas do mouse.*/
  void mudaXY(int,int);
};

#endif // PLOTTER_H
