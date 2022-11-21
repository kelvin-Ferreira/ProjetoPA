#include "cutsphere.h"
#include "Sculptor.h"

CutSphere::CutSphere(int _x0, int _y0, int _z0, int _raio)
{
    x0 = _x0;
    y0 = _y0;
    z0 = _z0;
    raio = _raio;
}

CutSphere::~CutSphere()
{

}

void CutSphere::draw(Sculptor &t)
{
    t.cutSphere(x0,y0,z0,raio);
}
