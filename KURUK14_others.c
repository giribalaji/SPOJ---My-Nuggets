#include <stdio.h>
#include <stdlib.h>

int main(void) {
 int t,n,temp,i,j,flag;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d",&n);
  int *a;
  flag = 0;
  a = calloc(n+1,sizeof(int));
  for ( i = 0 ; i < n ; i++)
  {
   scanf("%d",&temp);
   if(temp < n)
   {
    if(a[temp] == 0)
     a[temp] = 1;
    else
     a[n -1 - temp] = 1;
    
   }
  }
  
  for( i = 0 ; i<n;i++)
  {
   
   if(a[i] == 0)
   {
    flag  = 1;
    break;
   }
  }
  if(flag == 1)
   printf("NO\n");
  else
   printf("YES\n");
 }
 
 return 0;

}
