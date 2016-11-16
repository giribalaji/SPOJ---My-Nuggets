#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
     int n;
     scanf("%d",&n);
     while(n)
     {
          float r=0;
          r=(1/2.0)*(n*n)*(1/3.1415926);
          printf("%.2f\n",r);
          scanf("%d",&n);	
     }
     return 0;
}
