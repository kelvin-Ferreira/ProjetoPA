#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

class FiguraGeometrica
{
protected:
    int nx,ny,nz;
    float r, g, b, a;
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica();
    virtual void draw(Sculptor &t)=0;
};

#endif // FIGURAGEOMETRICA_H
