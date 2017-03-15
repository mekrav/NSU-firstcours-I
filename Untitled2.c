#include <stdio.h>
void main(){
    int m,h,k=0;
    float gm,gm1,gh,gh1;
    scanf("%d%d",&h, &m);
    gh = 30*h+ m/2.0;
    gm = 6*m;
    if(gh>=360) gh=gh-360;
    if(gm>=360) gm=gm-360;
    gh1=gh+0.5;
    gm1=gm+6;
    if(gm==gh)
        printf("%d",k);
    else {
        while((((gh-gm)*(gh1-gm1) > 0) || ((gm1-gh1) == 0)) && (k<10)) {
            k++;
            gh=gh1;
            gm=gm1;
            if(gh>=360) gh=gh-360;
            if(gm>=360) gm=gm-360;
            gh1 = gh+0.5;
            gm1 = gm+6;
            printf("%f %f %f",(gh-gm)*(gh1-gm1), gh,gm);
        }
        printf("\n %d",k);
    }
}
