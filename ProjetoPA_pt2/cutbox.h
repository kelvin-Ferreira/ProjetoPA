#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"
#include "Sculptor.h"

class CutBox : public FiguraGeometrica
{
    int x0, x1, y0, y1, z0, z1;
public:
    /*!Construtor da classe: Recebe as coordenadas iniciais e finais em X, Y e Z
       onde a figura sera apagada.*/
    CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);
    /*!Destrutor da classe.*/
    ~CutBox();
    /*!Recebe como parametro um objeto da classe 'Sculptor' e apaga dele uma caixa
       de medidas e coordenadas iguais as recebidas pelo construtor.*/
    void draw(Sculptor &t);
};
#endif // CUTBOX_H
