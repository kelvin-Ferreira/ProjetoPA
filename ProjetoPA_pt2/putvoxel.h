#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "Sculptor.h"
class PutVoxel : public FiguraGeometrica
{
    int x, y, z;
public:
    /*!Construtor da classe: Recebe as coordenadas em X, Y e Z
       onde a figura sera desenhada, alem dos valores (r, g, b, a)
       que iram atribuir cor e trasparencia a ela.*/
    PutVoxel(int _nx, int _ny, int _nz, float _r, float _g, float _b, float _a);
    /*!Destrutor da classe.*/
    ~PutVoxel();
    /*!Recebe como parametro um objeto da classe 'Sculptor' e desenha nele um voxel
       de coordenadas iguais as recebidas pelo construtor.*/
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
