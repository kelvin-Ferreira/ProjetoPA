#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "Sculptor.h"

class PutSphere : public FiguraGeometrica
{
    int x0, y0, z0, raio;
public:
    /*!Construtor da classe: Recebe as coordenadas centrais em X, Y e Z
       e o raio, onde a figura sera desenhada, alem dos valores (r, g, b, a)
       que iram atribuir cor e trasparencia a ela.*/
    PutSphere(int _x0, int _y0, int _z0, int _raio, float _r, float _g, float _b, float _a);
    /*!Destrutor da classe.*/
    ~PutSphere();
    /*!Recebe como parametro um objeto da classe 'Sculptor' e desenha nele uma esfera
       de medidas e coordenadas iguais as recebidas pelo construtor.*/
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
