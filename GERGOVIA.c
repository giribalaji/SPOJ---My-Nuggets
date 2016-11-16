#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    while(n!=0)
    {
        long int a[n];
        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
     long	int ans=0;
     	for(i=1;i<n;i++)
     	{
     		ans=ans+abs(a[i-1]);
			 a[i]=a[i-1]+a[i];
     			    		
     	}
            printf("%ld\n",ans);
         
		   scanf("%d",&n); 
        }
        
        
        return 0;
    }
