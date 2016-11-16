//SPOJ ALIENS
#include<stdio.h>

int main(void)
{
	unsigned long int N,M,add =0;
	int j=0,i=0,count=0,f=0;
	int loop;
	scanf("%d",&loop);
	while(loop--)
	{
		scanf("%lu %lu",&N,&M);
		int a[N];
		for(i=0;i<N;i++)
		{
			scanf("%lu",&a[i]);
			add=add+a[i];
			while(add>M)
			{
				
					add=add-a[j];
					
				
				j++;
			}
				
				if(((i-j+1)>f ) || (((i-j+1)==f)&&add>count))
				{
					count=add;
					f=i-j+1;
				}
			}
		
		printf("%lu %d\n",count,f);
		add=0;
		count=0;
		f=0;
		j=0;
	}
	return 0;
}
