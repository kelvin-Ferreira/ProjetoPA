#include "sculptor.h"

int main()
{
    Sculptor model(151,151,151);

    model.setColor(0,0,0,1);
    model.putVoxel(0,0,0);
    model.writeOFF("teste_1.off");
    model.cutVoxel(0,0,0);

    model.setColor(1,1,1,1);
    model.putBox(0,99,0,99,0,99);
    model.writeOFF("teste_2.off");
    model.cutBox(0,99,0,99,0,99);

    model.setColor(0,1,1,1);
    model.putSphere(50,50,50,50);
    model.writeOFF("teste_3.off");
    model.cutSphere(50,50,50,50);

    model.setColor(1,0,1,0.5);
    model.putEllipsoid(75,75,75,60,75,55);
    model.writeOFF("teste_4.off");
    model.cutEllipsoid(75,75,75,60,75,55);

    model.writeOFF("teste_5.off");

    return 0;
}    
