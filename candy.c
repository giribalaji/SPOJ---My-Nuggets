#include<stdio.h>
int main()
{
	int arr[100001];
	int n,val,tmp=0,i,res=0;
	scanf("%d",&n);
	while(n!=-1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			tmp=tmp+arr[i];
		}
			if(tmp%n==0)
		{
			val=tmp/n;
			for(i=0;i<n;i++)
			{
				if(arr[i]>val)
				{
					res=res+(arr[i]-val);
				}
			}
		printf("%d\n",res);
		}
	else
	{
		printf("-1\n");
	}
	scanf("%d",&n);	
	tmp=0,res=0;
	}
	
return 0;

}
