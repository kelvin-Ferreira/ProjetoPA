#include "cutellipisoid.h"
#include "Sculptor.h"

CutEllipisoid::CutEllipisoid(int _x0, int _y0, int _z0, int _rx, int _ry, int _rz)
{
    x0 = _x0;
    y0 = _y0;
    z0 = _z0;
    rx = _rx;
    ry = _ry;
    rz = _rz;
}

CutEllipisoid::~CutEllipisoid()
{

}

void CutEllipisoid::draw(Sculptor &t)
{
    t.cutEllipsoid(x0,y0,z0,rx,ry,rz);
}
