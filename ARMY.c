#include<stdio.h>
int main()
{
	int m,n,t;
//	int mg[10000]
	scanf("%d",&t);
	while(t--)
	{
	
	scanf("%d %d",&m,&n);
	
	int mg=0,g=0,tmg,tg;
	int i; 
	for(i=0;i<m;i++)
	{
		scanf("%d",&tmg);
		if(tmg>g)
		{
			g=tmg;
		}
	}
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmg);
		if(tmg>mg)
		{
			mg=tmg;
		}
	}
	//printf("mg = %d , g = %d\n",mg,g);
	
	if(mg>g)
	{
		printf("MechaGodzilla\n");
	}
	else
	{
		printf("Godzilla\n");
	}
	
}
return 0;	
}

