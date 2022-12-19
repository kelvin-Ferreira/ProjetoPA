#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

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
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
            }
        }
    }
}

Sculptor::~Sculptor(){
    delete[] v[0][0];
    delete[] v[0];
    delete[] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float _a){
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
    v[x][y][z].r = 0;
    v[x][y][z].g = 0;
    v[x][y][z].b = 0;
    v[x][y][z].a = 0;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i = 0, j = 0, k = 0;

    for(i=x0; i<=x1; i++){
        for(j=y0; j<=y1; j++){
            for(k=z0; k<=z1; k++){
                v[i][j][k].isOn = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }

    for(i=x0+1; i<=x1-1; i++){
        for(j=y0+1; j<=y1-1; j++){
            for(k=z0+1; k<=z1-1; k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    int i = 0, j = 0, k = 0;

    for(i=x0; i<=x1; i++){
        for(j=y0; j<=y1; j++){
            for(k=z0; k<=z1; k++){
                v[i][j][k].isOn = false;
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    int i = 0, j = 0, k = 0;
    float aux=0;

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                aux =(float)(((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter)));
                if((aux/(radius*radius))<=1){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                aux =(float)(((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter)));
                if((aux/((radius-1)*(radius-1)))<=1){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int i = 0, j = 0, k = 0;
    float aux=0;

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                aux = (float)(((i-xcenter)*(i-xcenter))+((j-ycenter)*(j-ycenter))+((k-zcenter)*(k-zcenter)));
                if((aux/(radius*radius))<=1){
                    v[i][j][k].isOn = false;
                    v[i][j][k].r = 0;
                    v[i][j][k].g = 0;
                    v[i][j][k].b = 0;
                    v[i][j][k].a = 0;
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int i = 0, j = 0, k = 0;
    float aux1 = 0, aux2 = 0, aux3 = 0;

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                aux1 = (float)((i-xcenter)*(i-xcenter));
                aux2 = (float)((j-ycenter)*(j-ycenter));
                aux3 = (float)((k-zcenter)*(k-zcenter));
                if(((aux1/(rx*rx))+(aux2/(ry*ry))+(aux3/(rz*rz)))<=1){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                aux1 = (float)((i-xcenter)*(i-xcenter));
                aux2 = (float)((j-ycenter)*(j-ycenter));
                aux3 = (float)((k-zcenter)*(k-zcenter));
                if(((aux1/((rx-1)*(rx-1)))+(aux2/((ry-1)*(ry-1)))+(aux3/((rz-1)*(rz-1))))<=1){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    int i = 0, j = 0, k = 0;
    float aux1 = 0, aux2 = 0, aux3 = 0;

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                aux1 = (float)((i-xcenter)*(i-xcenter));
                aux2 = (float)((j-ycenter)*(j-ycenter));
                aux3 = (float)((k-zcenter)*(k-zcenter));
                if(((aux1/(rx*rx))+(aux2/(ry*ry))+(aux3/(rz*rz)))<=1){
                    v[i][j][k].isOn = false;
                    v[i][j][k].r = 0;
                    v[i][j][k].g = 0;
                    v[i][j][k].b = 0;
                    v[i][j][k].a = 0;
                }
            }
        }
    }
}

void Sculptor::writeOFF(char* filename){
    int i = 0, j = 0, k = 0, n = 0, cont = 0;
    std::ofstream arquivo;

    arquivo.open(filename, std::ios::app);

    if(!arquivo.is_open()){
        exit(1);
    }

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if(v[i][j][k].isOn==true){
                    n++;
                }
            }
        }
    }

    arquivo << "OFF\n";
    arquivo << n*8 << " " << n*6 << " " << 0 << std::endl;
    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if(v[i][j][k].isOn==true){
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
    }

    for(i=0; i<nx; i++){
        for(j=0; j<ny; j++){
            for(k=0; k<nz; k++){
                if(v[i][j][k].isOn==true){
                    arquivo << std::fixed << std::setprecision(1);
                    arquivo << 4 << " " << cont*8+0 << " " << cont*8+3 << " " << cont*8+2 << " " << cont*8+1 << " ";
                    arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    arquivo << 4 << " " << cont*8+4 << " " << cont*8+5 << " " << cont*8+6 << " " << cont*8+7 << " ";
                    arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    arquivo << 4 << " " << cont*8+0 << " " << cont*8+1 << " " << cont*8+5 << " " << cont*8+4 << " ";
                    arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    arquivo << 4 << " " << cont*8+0 << " " << cont*8+4 << " " << cont*8+7 << " " << cont*8+3 << " ";
                    arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    arquivo << 4 << " " << cont*8+3 << " " << cont*8+7 << " " << cont*8+6 << " " << cont*8+2 << " ";
                    arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    arquivo << 4 << " " << cont*8+1 << " " << cont*8+2 << " " << cont*8+6 << " " << cont*8+5 << " ";
                    arquivo << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                cont++;
                }

            }
        }
    }

    arquivo.close();

    std::cout << "O modelo '" << filename << "' foi criado." << std::endl;
}
