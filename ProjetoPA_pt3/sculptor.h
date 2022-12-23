#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
  float
  /*!determina a dosagem de vermelho da cor do voxel,
   * assume valores de 0 a 1.*/r,
  /*!determina a dosagem de verde da cor do voxel,
   * assume valores de 0 a 1.*/g,
  /*!determina a dosagem de azul da cor do voxel,
   * assume valores de 0 a 1.*/b;

  /*!determina a transparência do voxel, assume valores de 0 a 1*/
  float a;
  /*!determina se o voxel ira ser incluido "true" ou não
   * "false" no desenho.*/
  bool isOn;
};

class Sculptor {
private:
  Voxel ***v; // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  /*!Construtor padrão da classe: Cria o intervalo de (0,0,0) a (99,99,99),
   *  dentro de onde a escultura pode ser desenhada.*/
  Sculptor();
  ~Sculptor();
  /*!Atribui a cor e transparência atual do desenho.\n
   *Seus parametros recebem valores no intervalode de 0 a 1.*/
  void setColor(float r, float g, float b, float alpha);
  /*!Cria um voxel nas coordenadas (x,y,z) da escultura,
   * atribuindo a ele a cor e transparência atuais do desenho.*/
  void putVoxel(int x, int y, int z);
  /*!Apaga o voxel nas coordenadas (z,y,z)*/
  void cutVoxel(int x, int y, int z);
  /*!Constrói uma 'caixa' criando voxels em (x,y,z) dentro do
   * intervalo x=(x0 a x1), y=(y0 a y1) e z=(z0 a z1) e
   * atribui a ela a cor e transparência atuais do desenho.*/
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /*!Destrói uma 'caixa' apagando voxels em (x,y,z) dentro do
   * intervalo x=(x0 a x1), y=(y0 a y1) e z=(z0 a z1).*/
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /*!Contrói uma esfera com centro em (xcenter, ycenter, zcenter)
   * de raio = radius, e atribui a ela a cor e transparência atuais do desenho. */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /*!Apaga uma esfera com centro em (xcenter, ycenter, zcenter)
   * de raio = radius. */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /*!Contrói um elipsóide com centro em (xcenter, ycenter, zcenter)
   * de raios rx ao longo de X, ry ao longo de Y e rz ao longo de Z,
   * e atribui a ele a cor e transparência atuais do desenho */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /*!Apaga um elipsóide com centro em (xcenter, ycenter, zcenter)
   * de raios rx ao longo de X, ry ao longo de Y e rz ao longo de Z. */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /*!Grava a escultura no arquivo "filename" com formato OFF que pode ser
   * executado num software externo (MeshLab, GeomView).*/
  void writeOFF(char* filename);
};

#endif // SCULPTOR_H
