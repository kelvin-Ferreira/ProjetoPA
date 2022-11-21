#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "Sculptor.h"

class CutVoxel : public FiguraGeometrica
{
    int x, y, z;
public:
    CutVoxel(int _nx, int _ny, int _nz);
    ~CutVoxel();
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
