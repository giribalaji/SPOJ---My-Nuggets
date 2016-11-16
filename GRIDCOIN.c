#include<stdio.h>>

int main(){
	int t,n,m,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&r);
		int a;
		if(n>m)
			a=n;
		else
			a=m;
		if(a>r)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n",n*m);
		}
	}
	
	return 0;
}
