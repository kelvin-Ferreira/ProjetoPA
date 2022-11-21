#include "putellipisoid.h"
#include "Sculptor.h"

PutEllipisoid::PutEllipisoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
    x0 = _x0;
    y0 = _y0;
    z0 = _z0;
    rx = _rx;
    ry = _ry;
    rz = _rz;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

PutEllipisoid::~PutEllipisoid()
{

}

void PutEllipisoid::draw(Sculptor &t)
{
    t.setColor(r,g,b,a);
    t.putEllipsoid(x0,y0,z0,rx,ry,rz);
}
