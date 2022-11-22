#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

class FiguraGeometrica
{
protected:
    int nx,ny,nz;
    float r, g, b, a;
public:
    /*!Construtor padrão da classe abstrata*/
    FiguraGeometrica();
    /*!Destrutor virtual da classe abstrata.*/
    virtual ~FiguraGeometrica();
    /*!Metodo da classe abstrata: Recebe como parametro um objeto da classe 'Sculptor' */
    virtual void draw(Sculptor &t)=0;
};

#endif // FIGURAGEOMETRICA_H
