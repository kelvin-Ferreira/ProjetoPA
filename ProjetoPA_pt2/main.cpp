#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Sculptor.h"
#include "figurageometrica.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipisoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipisoid.h"

int main(){
  std::vector<FiguraGeometrica*> figs;
  std::vector<FiguraGeometrica*>::iterator itf;

  std::ifstream fin;
  int dx=0, dy=0, dz=0;
  fin.open("c:\\teste.txt");

  if(!fin.is_open()){
    std::cout << "Erro: não foi possivel ler o arquivo\n";
    exit(EXIT_FAILURE);
  }

  std::string s;
  float r, g, b,a;
  while(fin.good()){
    fin >> s;
    if(!fin.good())
      break;
    if(s.compare("dim")==0){
      fin >> dx >> dy >> dz;
    }
    if(s.compare("putvoxel")==0){
      int x, y, z;
      fin >> x >> y >> z;
      fin >> r >> g >> b >> a;
      figs.push_back(new PutVoxel(x,y,z,r,g,b,a));
    }
    if(s.compare("cutvoxel")==0){
      int x, y, z;
      fin >> x >> y >> z;
      figs.push_back(new CutVoxel(x,y,z));
    }
    if(s.compare("putbox")==0){
      int x0, x1, y0, y1, z0, z1;
      fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
      fin >> r >> g >> b >> a;
      figs.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
    }
    if(s.compare("cutbox")==0){
      int x0, x1, y0, y1, z0, z1;
      fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
      figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
    }
    if(s.compare("putsphere")==0){
      int x0, y0, z0, raio;
      fin >> x0 >> y0 >> z0 >> raio;
      fin >> r >> g >> b >> a;
      figs.push_back(new PutSphere(x0,y0,z0,raio,r,g,b,a));
    }
    if(s.compare("cutsphere")==0){
      int x0, y0, z0, raio;
      fin >> x0 >> y0 >> z0 >> raio;
      figs.push_back(new CutSphere(x0,y0,z0,raio));
    }
    if(s.compare("putellipsoid")==0){
      int x0, y0, z0, rx, ry, rz;
      fin >> x0 >> y0 >> z0 >> rx >> ry >> rz;
      fin >> r >> g >> b >> a;
      figs.push_back(new PutEllipisoid(x0,y0,z0,rx,ry,rz,r,g,b,a));
    }
    if(s.compare("cutellipsoid")==0){
      int x0, y0, z0, rx, ry, rz;
      fin >> x0 >> y0 >> z0 >> rx >> ry >> rz;
      figs.push_back(new CutEllipisoid(x0,y0,z0,rx,ry,rz));
    }
  }

  Sculptor t(dx,dy,dz);

  for(auto it: figs){
    it->draw(t);
  }

  for(itf = figs.begin(); itf!=figs.end(); itf++){
    delete *itf;
  }
    t.writeOFF("teste.off");
  return 0;
}
