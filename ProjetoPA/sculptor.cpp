#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    int  i=0, j=0, k=0;
    v = new Voxel**[nx];
    v[0]= new Voxel*[nx*ny];
    v[0][0]= new Voxel[nx*ny*nz];

    for(k=1; k<nx; k++){
        v[k]=v[k-1]+ny;
    }

    for(k=0; k<nx; k++){
        for(i=0; i<ny; i++){
            if(i==0&&k==0){

            }else{
                if(i==0){
                    v[k][i]=v[k-1][ny-1]+nz;
                }else{
                v[k][i]=v[k][i-1]+nz;
                }
            }
        }
    }

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                v[i][j][k].isOn = false;
                v[i][j][k].r_ = 0;
                v[i][j][k].g_ = 0;
                v[i][j][k].b_ = 0;
                v[i][j][k].a_ = 0;
            }
        }
    }
}
Sculptor::~Sculptor()
{
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

float Sculptor::getr(int x, int y, int z){
    return v[x][y][z].r_;
}

float Sculptor::getg(int x, int y, int z){
    return v[x][y][z].g_;
}

float Sculptor::getb(int x, int y, int z){
    return v[x][y][z].b_;
}

float Sculptor::geta(int x, int y, int z){
    return v[x][y][z].a_;
}
void Sculptor::setColor(float _r, float _g, float _b, float _a){
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r_ = r;
    v[x][y][z].g_ = g;
    v[x][y][z].b_ = b;
    v[x][y][z].a_ = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
    v[x][y][z].r_ = 0;
    v[x][y][z].g_ = 0;
    v[x][y][z].b_ = 0;
    v[x][y][z].a_ = 0;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i = 0, j = 0, k = 0;

    for(i=x0-1; i<x1; i++){
        for(j=y0-1; j<y1; j++){
            for(k=z0-1; k<z1; k++){
                v[i][j][k].isOn = true;
                v[i][j][k].r_ = r;
                v[i][j][k].g_ = g;
                v[i][j][k].b_ = b;
                v[i][j][k].a_ = a;
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i = 0, j = 0, k = 0;

    for(i=x0-1; i<x1; i++){
        for(j=y0-1; j<y1; j++){
            for(k=z0-1; k<z1; k++){
                v[i][j][k].isOn = false;
                v[i][j][k].r_ = 0;
                v[i][j][k].g_ = 0;
                v[i][j][k].b_ = 0;
                v[i][j][k].a_ = 0;
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    int i = 0, j = 0, k = 0, aux=0;

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                aux=(((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter)));
                if((aux/(radius*radius))<=1){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r_ = r;
                    v[i][j][k].g_ = g;
                    v[i][j][k].b_ = b;
                    v[i][j][k].a_ = a;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int i = 0, j = 0, k = 0, aux=0;

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                aux=(((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter)));
                if((aux/(radius*radius))<=1){
                    v[i][j][k].isOn = false;
                    v[i][j][k].r_ = 0;
                    v[i][j][k].g_ = 0;
                    v[i][j][k].b_ = 0;
                    v[i][j][k].a_ = 0;
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename){
    std::ofstream arquivo;
    int i = 0, j = 0, k = 0, cont=0;
    arquivo.open(filename, std::ios::app);

    arquivo << "OFF\n";
    arquivo << nx*ny*nz*8 << " " << nx*ny*nz*6 << " " << 0 << std::endl;
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                arquivo << i-0.5 << " " << j+0.5 << " " << k-0.5 << std::endl;
                arquivo << i-0.5 << " " << j-0.5 << " " << k-0.5 << std::endl;
                arquivo << i+0.5 << " " << j-0.5 << " " << k-0.5 << std::endl;
                arquivo << i+0.5 << " " << j+0.5 << " " << k-0.5 << std::endl;
                arquivo << i-0.5 << " " << j+0.5 << " " << k+0.5 << std::endl;
                arquivo << i-0.5 << " " << j-0.5 << " " << k+0.5 << std::endl;
                arquivo << i+0.5 << " " << j-0.5 << " " << k+0.5 << std::endl;
                arquivo << i+0.5 << " " << j+0.5 << " " << k+0.5 << std::endl;
            }
        }
    }

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if(v[i][j][k].isOn==true){
                    arquivo << std::fixed << std::setprecision(1);
                    arquivo << 4 << " " << cont*8+0 << " " << cont*8+3 << " " << cont*8+2 << " " << cont*8+1 << " ";
                    arquivo << v[i][j][k].r_ << " " << v[i][j][k].g_ << " " << v[i][j][k].b_ << " " << v[i][j][k].a_ << "\n";
                    arquivo << 4 << " " << cont*8+4 << " " << cont*8+5 << " " << cont*8+6 << " " << cont*8+7 << " ";
                    arquivo << v[i][j][k].r_ << " " << v[i][j][k].g_ << " " << v[i][j][k].b_ << " " << v[i][j][k].a_ << "\n";
                    arquivo << 4 << " " << cont*8+0 << " " << cont*8+1 << " " << cont*8+5 << " " << cont*8+4 << " ";
                    arquivo << v[i][j][k].r_ << " " << v[i][j][k].g_ << " " << v[i][j][k].b_ << " " << v[i][j][k].a_ << "\n";
                    arquivo << 4 << " " << cont*8+0 << " " << cont*8+4 << " " << cont*8+7 << " " << cont*8+3 << " ";
                    arquivo << v[i][j][k].r_ << " " << v[i][j][k].g_ << " " << v[i][j][k].b_ << " " << v[i][j][k].a_ << "\n";
                    arquivo << 4 << " " << cont*8+3 << " " << cont*8+7 << " " << cont*8+6 << " " << cont*8+2 << " ";
                    arquivo << v[i][j][k].r_ << " " << v[i][j][k].g_ << " " << v[i][j][k].b_ << " " << v[i][j][k].a_ << "\n";
                    arquivo << 4 << " " << cont*8+1 << " " << cont*8+2 << " " << cont*8+6 << " " << cont*8+5 << " ";
                    arquivo << v[i][j][k].r_ << " " << v[i][j][k].g_ << " " << v[i][j][k].b_ << " " << v[i][j][k].a_ << "\n";
                }else{
                    arquivo << 4 << " " << "*" << " " << "*" << " " << "*" << " " << "*" << " ";
                    arquivo << "*" << " " << "*" << " " << "*" << " " << "*" << std::endl;
                    arquivo << 4 << " " << "*" << " " << "*" << " " << "*" << " " << "*" << " ";
                    arquivo << "*" << " " << "*" << " " << "*" << " " << "*" << std::endl;
                    arquivo << 4 << " " << "*" << " " << "*" << " " << "*" << " " << "*" << " ";
                    arquivo << "*" << " " << "*" << " " << "*" << " " << "*" << std::endl;
                    arquivo << 4 << " " << "*" << " " << "*" << " " << "*" << " " << "*" << " ";
                    arquivo << "*" << " " << "*" << " " << "*" << " " << "*" << std::endl;
                    arquivo << 4 << " " << "*" << " " << "*" << " " << "*" << " " << "*" << " ";
                    arquivo << "*" << " " << "*" << " " << "*" << " " << "*" << std::endl;
                    arquivo << 4 << " " << "*" << " " << "*" << " " << "*" << " " << "*" << " ";
                    arquivo << "*" << " " << "*" << " " << "*" << " " << "*" << std::endl;
               }
                cont++;
            }
        }
    }
    arquivo.close();
}



