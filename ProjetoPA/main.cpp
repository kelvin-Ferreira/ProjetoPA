#include "sculptor.h"

int main()
{
    Sculptor model(200,200,200);
    int i = 0, j = 0, k = 0;

    model.setColor(0.5,0.5,0.5,1);
    model.putSphere(40,72,40+40,10);
    model.putBox(36,44,80,80,36+40,84);
    model.putEllipsoid(40,76,80,9,1,9);

    for(i=0; i<200; i++){
        for(j=0; j<200; j++){
            for(k=0; k<200; k++){
                if(j<76 || j>80){
                    model.cutVoxel(i,j,k);
                }
            }
        }
    }

    for(i=0; i<5; i++){
        model.setColor(0.4,0.4,0.4,1);
        model.putEllipsoid(38+i,40,80-30-10,1,20,12);
        model.putEllipsoid(38+i,40,80+30+10,1,20,12);
        model.cutEllipsoid(38+i,40,80-30-10-4,1,12,8);
        model.cutEllipsoid(38+i,40,80+30+10+4,1,12,8);
    }
    model.cutBox(36,44,40,40,40,40);
    model.cutBox(36,44,40,40,120,120);
    model.cutBox(38,42,20,20,120,120);
    model.cutBox(38,42,60,60,120,120);
    model.cutBox(38,42,20,20,40,40);
    model.cutBox(38,42,60,60,40,40);

    model.putBox(38,42,21,59,120,140);
    model.putBox(38,42,21,59,20,40);
    model.putBox(39,41,50,50,120,140);
    model.putBox(39,41,30,30,120,140);
    model.putBox(39,41,50,50,20,40);
    model.putBox(39,41,30,30,20,40);

    model.setColor(1,0,0,1);
    model.putBox(38,42,50,59,140,145);
    model.putBox(38,42,21,30,15,20);
    model.setColor(0,0,1,1);
    model.putBox(38,42,50,59,15,20);
    model.putBox(38,42,21,30,140,145);

    model.cutBox(38,42,31,49,120,140);
    model.cutBox(38,42,31,49,20,40);

    model.setColor(0.7,0.7,0.7,1);
    model.putSphere(20*2,20*2,20*2+40,15*2);
    model.setColor(0.1,0.1,0.1,1);
    model.putVoxel(5*2,20*2,20*2+40);

    for(i=5*2; i<2*35; i++){
        for(j=5*2; j<2*35; j++){
            for(k=5*2+40; k<35*2+40; k++){
                if(i==11 || i==12){
                    if(j>14*2 && j<26*2){
                        if(k>14*2+40 && k<26*2+40){
                            if((float)(((i-20*2)*(i-20*2))+((j-20*2)*(j-20*2))+((k-(20*2+40))*(k-(20*2+40))))/(15*2*15*2)<=1){
                                model.setColor(1,1,1,1);
                                model.putVoxel(i,j,k);
                            }
                        }
                    }
                }
            }
        }
    }

    model.setColor(0.5,0.5,0.5,1);
    model.putBox(38,42,34*2,39*2,39+40,41+40);
    model.putBox(39,41,34*2,39*2,38+40,42+40);
    model.putSphere(15,20,65,5);
    model.putSphere(15,20,95,5);

    model.writeOFF("Magnemite.off");
    return 0;
}    
