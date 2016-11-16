#include<stdio.h>

int main()
 {
 	long long int t,n,d,f,l,ans,i;
 
	long long int a[26];
	a[0]=1;
	a[1]=3;
	for(i=2;i<=25;i++)
	{
		a[i]=2*a[i-1]+a[i-2];
	}
		
 	scanf("%lld",&n);
	 	printf("%lld\n",a[n]);
 
 		
 		return 0;
 	}
