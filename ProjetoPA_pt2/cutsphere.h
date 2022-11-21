#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "Sculptor.h"

class CutSphere : public FiguraGeometrica
{
    int x0, y0, z0, raio;
public:
    CutSphere(int _x0, int _y0, int _z0, int _raio);
    ~CutSphere();
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
