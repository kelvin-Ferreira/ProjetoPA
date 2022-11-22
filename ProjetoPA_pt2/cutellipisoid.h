#ifndef CUTELLIPISOID_H
#define CUTELLIPISOID_H
#include "figurageometrica.h"
#include "Sculptor.h"

class CutEllipisoid : public FiguraGeometrica
{
    int x0, y0, z0, rx, ry, rz;
public:
    /*!Construtor da classe: Recebe as coordenadas centrais em X, Y e Z
       e seus respectivos raios, onde a figura sera apagada.*/
    CutEllipisoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz);
    /*!Destrutor da classe.*/
    ~CutEllipisoid();
    /*!Recebe como parametro um objeto da classe 'Sculptor' e apaga dele um elipsoide
       de medidas e coordenadas iguais as recebidas pelo construtor.*/
    void draw(Sculptor &t);
};

#endif // CUTELLIPISOID_H
