#include <cstdio>
using namespace std;
int main()
{
	int l,k,n,i,flag=1;
	int arr[100003];
	char st[2]="AB";
	scanf("%d%d%d",&k,&l, &n);
	//printf("giri %d %d %d\n",k,l,n);
	int m=n;
	arr[0]=1;
	arr[1]=0;
	for(i=2;i<=100002;i++)
	{
		flag=1;
		if(arr[i-1]==1)
			flag=0;
		if(i>=k&&arr[i-k]==1)
			flag=0;
		if(i>=l&&arr[i-l]==1)
			flag=0;
	arr[i]=flag;
	}
	
	for(i=0;i<=20;i++)
	{
		printf("%d  %d\n",i,arr[i]);
	}
	
	//printf("giri %d %d %d",k,l,m);
int g;	
	for(i=0;i<m;i++)
	{
		//printf("giri");
		scanf("%d",&g);
		printf("%c",st[arr[g]]);
	}
printf("\n");
	return 0;
}
