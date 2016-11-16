#include<stdio.h>
int main()
{
	int m,n,t;
	scanf("%d",&t);
	while(t--)
	{
	m=0;
	int n1;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&n1);
		m=m+n1;
	}

	if(m%n)
			printf("%d\n",n-1);
		else
			printf("%d\n",n);
	}
	
	
	return 0;
}
