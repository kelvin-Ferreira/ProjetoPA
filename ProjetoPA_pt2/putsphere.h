#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "Sculptor.h"

class PutSphere : public FiguraGeometrica
{
    int x0, y0, z0, raio;
public:
    PutSphere(int _x0, int _y0, int _z0, int _raio, float _r, float _g, float _b, float _a);
    ~PutSphere();
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
