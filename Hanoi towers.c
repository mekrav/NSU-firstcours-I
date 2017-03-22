#include <stdio.h>
#define M 3
void disk (int n,int s1,int s2){
    printf("Remove disk %d from %d to %d \n", n, s1,s2);
}
void tower (int n, int s1, int s2) {
    int k,s3;
    if (n==1) disk(n,s1,s2);
    else {
        s3=6-s1-s2;
        k=n-1;
        tower(k,s1,s3);
        disk(n,s1,s2);
        tower(k,s3,s2);
    }
}
main(){
    int n, s1, s2;
    scanf("%d %d %d", &n, &s1, &s2);
    printf("To transfer a tower of %d disks from %d to %d you need to do following steps \n", n,s1,s2);
    tower(n,s1,s2);
}
