#include <stdio.h>
#include <math.h>
float ger(float x1, float y1, float x2, float y2, float x3, float y3)
{
  float S,a12,b23,c31,p;
  a12=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  b23=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
  c31=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
  p=(a12+b23+c31)/2;
  S=sqrt(p*(p-a12)*(p-b23)*(p-c31));
  return S;
}
void main()
{ float a1,a2,b1,b2,c1,c2,S,S0,e;
  printf("Enter the coordinates \n");
  scanf("%f%f", &a1, &a2);
  printf("\n");
  scanf("%f%f", &b1, &b2);
  printf("\n");
  scanf("%f%f", &c1, &c2);
  printf("\n");
  S=ger(a1,a2,b1,b2,c1,c2);
  S0=ger(a1,a2,b1,b2,0,0)+ger(c1,c2,b1,b2,0,0)+ger(a1,a2,c1,c2,0,0);
  if((ger(a1,a2,b1,b2,0,0) < 0.001) || (ger(c1,c2,b1,b2,0,0) < 0.001) || (ger(a1,a2,c1,c2,0,0) < 0.001))
         printf("Origin on the side of triangle");
       else if (S0>S+e) printf("Origin outside the triangle");
            else printf("Origin inside the triangle");
}
