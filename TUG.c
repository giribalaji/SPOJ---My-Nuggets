#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
int arr[100005];
int findPartiion (int arr[], int n)
{
    int sum = 0;
    int i, j;
   
    
    for (i = 0; i < n; i++)
      sum += arr[i];
     
    if (sum%2 != 0)  
       return false;
   
    int part[sum/2+1][n+1];
     
    
    for (i = 0; i <= n; i++)
      part[0][i] = true;
       
    
    for (i = 1; i <= sum/2; i++)
      part[i][0] = false;     
      
     
     for (i = 1; i <= sum/2; i++)  
     {
       for (j = 1; j <= n; j++)  
       {
         part[i][j] = part[i][j-1];
         if (i >= arr[j-1])
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
       }        
     }    
      
   
      
     return part[sum/2][n];
}     
 

int main()
{
  
  int t,n,i;
  scanf("%d",&t);
  while(t--)
  {
  
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  	scanf("%d",&arr[i]);
  }
  if (findPartiion(arr, n) == true)
     printf("YES\n");
  else
     printf("NO\n");
  memset(arr,0,sizeof(arr));
}
    return 0;
}
