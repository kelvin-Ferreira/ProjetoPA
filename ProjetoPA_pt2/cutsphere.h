#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "Sculptor.h"

class CutSphere : public FiguraGeometrica
{
    int x0, y0, z0, raio;
public:
    /*!Construtor da classe: Recebe as coordenadas centrais em X, Y e Z
       e o raio, onde a figura sera apagada.*/
    CutSphere(int _x0, int _y0, int _z0, int _raio);
    /*!Destrutor da classe.*/
    ~CutSphere();
    /*!Recebe como parametro um objeto da classe 'Sculptor' e apaga dele uma esfera
       de medidas e coordenadas iguais as recebidas pelo construtor.*/
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
