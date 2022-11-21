#include "putsphere.h"

PutSphere::PutSphere(int _x0, int _y0, int _z0, int _raio, float _r, float _g, float _b, float _a)
{
    x0 = _x0;
    y0 = _y0;
    z0 = _z0;
    raio = _raio;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

PutSphere::~PutSphere()
{

}

void PutSphere::draw(Sculptor &t)
{
    t.setColor(r,g,b,a);
    t.putSphere(x0,y0,z0,raio);
}
