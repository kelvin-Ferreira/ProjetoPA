#include <iostream>
#include "sculptor.h"

int main()
{
    int i = 0, j = 0, k = 0, x = 0, y = 0, z = 0;
    float r = 0, g = 0, b = 0, a = 0;
    bool visivel=0;

    std::cout << "Entre com os valores de X, Y e Z:" << std::endl;
    std::cin >> x >> y >> z;

    Sculptor model(x,y,z);
    int x1 = 0, y1 = 0, z1 = 0, x0 = 0, y0 = 0, z0 = 0;

    std::cout << "Entre com o intervalo de voxels que deseja manipular:" << std::endl;
    std::cin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
    for(i=x0-1; i<x1; i++){
        for(j=y0-1; j<y1; j++){
            for(k=z0-1; k<z1; k++){
                std::cout << "O voxel na posição (" << i <<"," << j << "," << k << ") fara parte da figura?" << std::endl;
                std::cout << "'1' para sim, '0' para não" << std::endl;
                std::cin >> visivel;
                if(visivel==true){
                    std::cout << "Entre com os valores (0 a 1) de R, G, B, e A:" << std::endl;
                    std::cin >> r >> g >> b >> a;
                    model.setColor(r, g, b, a);
                    model.putVoxel(i, j, k);
                }else{model.cutVoxel(i,j,k);}
            }
        }
    }
    model.setColor(1,0,0,0.5);
    model.putSphere(9,9,9,6);
    model.cutSphere(9,8,7,6);

    model.writeOFF("teste0.off");


    return 0;
}    
