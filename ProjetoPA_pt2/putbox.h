#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "Sculptor.h"

class PutBox : public FiguraGeometrica
{
    int x0, x1, y0, y1, z0, z1;
public:
    /*!Construtor da classe: Recebe as coordenadas iniciais e finais em X, Y e Z
       onde a figura sera desenhada, alem dos valores (r, g, b, a) que iram atribuir
       cor e trasparencia a ela.*/
    PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
    /*!Destrutor da classe.*/
    ~PutBox();
    /*!Recebe como parametro um objeto da classe 'Sculptor' e desenha nele uma caixa
       de medidas e coordenadas iguais as recebidas pelo construtor.*/
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
