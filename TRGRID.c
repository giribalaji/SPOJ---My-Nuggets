#include<stdio.h>
int main()
{
	int m,n,t;
	scanf("%d",&t);
	while(t--)
	{
	
	scanf("%d %d",&m,&n);
	if(m>n)
	{
		if(n%2)
			printf("D\n");
		else
			printf("U\n");
	}
	else
	{
		if(m%2)
			printf("R\n");
		else
			printf("L\n");
	}
	
	}
	return 0;
}
