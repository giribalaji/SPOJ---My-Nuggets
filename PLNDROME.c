#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 205

int fun(char *p)
{
	int k=strlen(p);
	char *q=p+k-1;
	while(p<q)
	{
//		printf("%s   %s\n",p,q);
		if(*p!=*q)
		{
			return 0;
		
		}
		else
		{
			p++;
			q--;
		}
	}
	return 1;
}


int main()
{

	
	int t;
	scanf("%d",&t);
	int t1=1;
	while(t1<=t)
	{
	
	char arr[200005];
	char *m=arr;
	int n,q,z;
	char c;
	scanf("%d",&n);
	scanf("%s",m);
	scanf("%d",&q);
	printf("Case %d:\n",t1);
	t1++;
	while(q--)
	{
	scanf("%d %c",&z,&c);
	m[z-1]=c;
//	printf("%s\n",m);

	if(fun(m))
	{
	printf("YES\n");
		}
		else
		{
		printf("NO\n");	
		}
}


}

return 0;
}
