#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	char *str="manku";
	while(t--)
	{
		int n=1,in,pn;
		scanf("%d",&in);
		int tmp=in;
		int st=5;
		pn=0;
		while(st<in)
		{
		
			//tmp=tmp-st;
			n++;
			pn=st;
			st=st+pow(5,n);
			//n++;
			
				
		}
		tmp=tmp-pn;
		//printf("tmp=%d \n",tmp);
		pn=n-1;
	//	printf("n=%d \n",n);
		int i;
		for(i=n-1;i>=0;i--)	
		{
			int t=pow(5,i);
		//	printf("t=%d \n",t);
			int s=tmp%t;
	//		printf("s=%d \n",s);
			int a=tmp/t;
	//		printf("a=%d \n",a);
			if(s==0)
			{
				 a=a-1;
			}
			tmp=tmp-(t*a);
			printf("%c",str[a]);
		}
		printf("\n");
	}
	
	return 0;
}
