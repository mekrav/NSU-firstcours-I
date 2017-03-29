#include <stdio.h>
int simple (int x, int y)  {
    if(x==y) return 1;
    else if ((y%x!=0) && (simple(x+1,y)==1)) return 1;
        else return 0; //вызывать simple(2,x)
}
int main(){
    int a,b=2,c,f=0;
    scanf("%d", &a);
    while (b <= a){
        if(simple(2,b)==1){
            c=a-b;
            if((simple(2,c)==1) && (f==0)) { printf("%d %d",b,c); f=1;}
        }
        b++;
    }
return 0;
}
