#include<stdio.h>

int max=1000000;
 int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}




int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		int a[n][3];
		
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		scanf("%d",&a[i][j]);
	}
		
	
	}
	return 0;
}
