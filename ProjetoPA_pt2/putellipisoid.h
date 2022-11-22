#ifndef PUTELLIPISOID_H
#define PUTELLIPISOID_H
#include "figurageometrica.h"

class PutEllipisoid : public FiguraGeometrica
{
    int x0, y0, z0, rx, ry, rz;
public:
    /*!Construtor da classe: Recebe as coordenadas centrais em X, Y e Z
       e seus respectivos raios, onde a figura sera desenhada, alem dos
       valores (r, g, b, a) que iram atribuir cor e trasparencia a ela.*/
    PutEllipisoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
    /*!Destrutor da classe.*/
    ~PutEllipisoid();
    /*!Recebe como parametro um objeto da classe 'Sculptor' e desenha nele um elipsoide
       de medidas e coordenadas iguais as recebidas pelo construtor.*/
    void draw(Sculptor &t);
};

#endif // PUTELLIPISOID_H
