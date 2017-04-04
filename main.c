#include <stdio.h>
struct data{
    int d;
    int m;
    int y;
    };
int vs(int y){
    int r=0;
    if (y % 4 == 0) {
        r=1;
        if (y % 100 == 0) {
            r=0;
            if (y % 400 == 0) r = 1;
            }
    }   return r;
}
int kd(int m, int y) {
    int d;
    switch (m){
        case 2:{d=28+vs(y);} break;
        case 4:{d=30;} break;
        case 6:{d=30;} break;
        case 9:{d=30;} break;
        case 11:{d=30;} break;
        default: {d=31;}
    }   return d;
}

void main() {
    int n,ost; //Если год высокосный 1, если 31 день 1
    struct data in,res;
    scanf("%d%d%d", &in.d, &in.m, &in.y);
    printf("\n");
    scanf("%d", &n);

    ost=kd(in.m,in.y)-in.d; //printf("%d\n",ost);
    if(n<=ost) {
        res.d=in.d+n;
        res.m=in.m; res.y=in.y;
        n=0;
    } else {res.d=0;
         res.m=in.m+1;
         res.y=in.y;
         if(in.m==12){res.m=1; res.y++;}
        n=n-ost;
    }

    while (n>=364+vs(in.y)) {
        n=n-364-vs(in.y);
        in.y++;
    }
    while (n>=kd(res.m,res.y)){
        n=n-kd(res.m,res.y);
        res.m=res.m++;
        if(res.m==13){res.m=1; res.y++;}
    }
    if(res.d==0) res.d=n;
    printf("%d.%d.%d",res.d,res.m,res.y);
}