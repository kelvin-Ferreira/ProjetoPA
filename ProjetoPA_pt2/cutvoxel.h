#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "Sculptor.h"

class CutVoxel : public FiguraGeometrica
{
    int x, y, z;
public:
    /*!Construtor da classe: Recebe as coordenadas em X, Y e Z
       onde a figura sera apagada.*/
    CutVoxel(int _nx, int _ny, int _nz);
    /*!Destrutor da classe.*/
    ~CutVoxel();
    /*!Recebe como parametro um objeto da classe 'Sculptor' e apaga dele um voxel
       de coordenadas iguais as recebidas pelo construtor.*/
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
