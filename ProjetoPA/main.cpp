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



    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            for(k=0; k<z; k++){
                std::cout << "O voxel na posição (" << i <<"," << j << "," << k << ") fara parte da figura?" << std::endl;
                std::cout << "'1' para sim, 0 para não" << std::endl;
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
    model.writeOFF("teste0.off");
    return 0;
}    
