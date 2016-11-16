#include<stdio.h>

int main()
 {
 	long long int t,n,d,f,l,ans;
 scanf("%lld",&t);
	int t1=1;
    
	while(t--)
	{
 		scanf("%lld",&n);
 		if(n%2)
 		{
 			d=n-2;
 		}
 		else
 		{
 			d=n-3;
 		}
 		
 		f=1;
 		l=d;
 		ans=(((d+1)/2)*(f+l)/2);
 		printf("%lld\n",ans%n);
 }
 		
 		return 0;
 	}
 		
 		
 		
