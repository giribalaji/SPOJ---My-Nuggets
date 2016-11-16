#include<stdio.h>

int main()
 {
 	long long int t,n,d,f,l,ans,i;
 scanf("%lld",&t);
	int t1=1;
   long long int a[46];
	a[0]=1;
	a[1]=2;
	for(i=2;i<=45;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	 
	while(t--)
	{

	 	scanf("%lld",&n);
	 	printf("%lld\n",a[n]);
 }
 		
 		return 0;
 	}
 		
