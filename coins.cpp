#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
	unsigned int n,st=0;
	//unsigned long int a[100001]={0};
	int i=1;
	//a=(int *)malloc(sizeof(int)*1000001);
	map<long int, long int>a;
	while(scanf("%ld",&n) != EOF)
	{
	//	a[0]=0;
		
		/*if(n == 0)
		{
		
			printf("%u\n",a[n]);
			continue;
	}*/
		
		
	
	/*if(n>st)
		i=n-st;*/
	st=n+1;
	if(a[n] == 0)
	{
		
		//	printf("%u\n",a[n]);
		//	continue;
	
		if(n>st)
			i=n-st;
		for(;i<=n;i++)
		{
			int tmp=a[i/2]+a[i/3]+a[i/4];
			if (i > tmp)
				a[i]=i;
			else
				a[i]=tmp;
		
		}
	 // printf("%u\n",a[n]);

      if (n > st)
	  st=n;
}
printf("%u\n",a[n]);

	}
	return 0;
}
	
