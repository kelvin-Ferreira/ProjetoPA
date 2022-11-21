#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "Sculptor.h"
class PutVoxel : public FiguraGeometrica
{
    int x, y, z;
public:
    PutVoxel(int _nx, int _ny, int _nz, float _r, float _g, float _b, float _a);
    ~PutVoxel();
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
