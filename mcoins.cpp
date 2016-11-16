#include <cstdio>
using namespace std;

int main()
{
	int l,k,n,i;
	bool arr[1000003],flag;
	
	scanf("%d%d%d",&k,&l, &n);
	//printf("giri %d %d %d\n",k,l,n);
	int m=n;
	arr[0]=1;
	arr[1]=0;
	for(i=2;i<=1000001;i++)
	{
		flag=true;
		if(arr[i-1]==1)
			flag=false;
		if(i>=k&&arr[i-k]==1)
			flag=false;
		if(i>=l&&arr[i-l]==1)
			flag=false;
	arr[i]=flag;
	}
	
	/*for(i=0;i<=20;i++)
	{
		printf("%d  %d\n",i,arr[i]);
	}*/
	
	//printf("giri %d %d %d",k,l,m);
int g;	
	for(i=0;i<m;i++)
	{
	
		scanf("%d",&g);
		if (arr[g])
			printf("B");
		else
			printf("A");
	}
printf("\n");
	return 0;
}
