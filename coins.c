#include<stdio.h>
int main()
{
	unsigned int n;
	//unsigned long int a[100001]={0};
	int i, *a;
	a=(int *)malloc(sizeof(int)*1000001);
	while(scanf("%ld",&n) != EOF)
	{
		a[0]=0;
		for(i=1;i<=n;i++)
		{
			int tmp=a[i/2]+a[i/3]+a[i/4];
			if (i > tmp)
				a[i]=i;
			else
				a[i]=tmp;
		
		}
	  printf("%u\n",a[n]);
	  
	}
	return 0;
}
	
