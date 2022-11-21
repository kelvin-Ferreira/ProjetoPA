#ifndef PUTELLIPISOID_H
#define PUTELLIPISOID_H
#include "figurageometrica.h"

class PutEllipisoid : public FiguraGeometrica
{
public:
    int x0, y0, z0, rx, ry, rz;
    PutEllipisoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
    ~PutEllipisoid();
    void draw(Sculptor &t);
};

#endif // PUTELLIPISOID_H
