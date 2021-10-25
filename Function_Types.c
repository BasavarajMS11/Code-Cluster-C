/* Distance between two points*/
#include<stdio.h>
#include<math.h>

float findsqrt(float n){
    return sqrt(n);
}

float findpower(float n,float m){
    return pow(n,m);
}

float finddistance(float a1,float a2,float b1, float b2){
    float t1,t2,distance;
    t1=findpower(a2-a1,2);
    t2=findpower(b2-b1,2);
    distance=findsqrt(t1+t2);
    return distance;
}

int main()
{
   float d,x1=2,x2=4,y1=3,y2=4;

   d = finddistance(x1,x2,y1,y2);

   printf("Distance between 2 points = %.2f",d);
   return 0;
}