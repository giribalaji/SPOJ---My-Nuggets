#include<stdio.h>

int main()
{
	int n,a,b,d,s,c,dif;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&a,&b);
		dif=a-b;
		c=a%2;
		d=b%2;
		s=(c==d?1:0);
		//printf("dif=%d\n",d);
		if(dif>2||dif<0||s==0)
		{
			printf("No Number\n");
		}
		else if(c==0&&d==0)
		{
			printf("%d\n",a+b);
		}
		else 
		{
			printf("%d\n",(a+b-1));
		}
	}
	//printf("%d",z%2)	;
	return 0;
}
