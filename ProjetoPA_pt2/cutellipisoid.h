#ifndef CUTELLIPISOID_H
#define CUTELLIPISOID_H
#include "figurageometrica.h"
#include "Sculptor.h"

class CutEllipisoid : public FiguraGeometrica
{
public:
    int x0, y0, z0, rx, ry, rz;
    CutEllipisoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz);
    ~CutEllipisoid();
    void draw(Sculptor &t);
};

#endif // CUTELLIPISOID_H
