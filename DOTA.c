#include <stdio.h>
 
int main()
{
    int t,n,m,d,a[501],cnt=0,i;
    
    scanf("%d",&t);
    while(t--)
    {
    	cnt=0;
		scanf("%d %d %d",&n,&m,&d);
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    	while((a[i]-d) > 0)
    	{
    		cnt++;
    		a[i]=a[i]-d;
		}
    }
	
	if(cnt>=m)
    	printf("YES\n");
    else
    	printf("NO\n");
	}
    
    
    return 0;
}
