#ifndef SCULPTOR_H
#define SCULPTOR_H

class Sculptor {  
  private:
  struct Voxel{
  float r_, g_, b_;
  float a_;
  bool isOn;
  };
  int nx,ny,nz;
  Voxel ***v;
  float r,g,b,a; // Current drawing color
public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();
  float getr(int x, int y, int z);
  float getg(int x, int y, int z);
  float getb(int x, int y, int z);
  float geta(int x, int y, int z);
  void setColor(float _r, float _g, float _b, float _a);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(const char* filename);
};
#endif // SCULPTOR_H
