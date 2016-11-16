#include<stdio.h>
//int arr[] = {10,22,33, 41, 50, 60,80,130};

//int arr[]={50, 10, 20, 30, 40};

//int arr[]={21 ,45 ,30 ,12, 14 };

//int n = sizeof(arr)/sizeof(arr[0]);

int arr[1002];
int mem[1002][1002]={0};
int max(int a, int b)
{
    return (a > b)? a : b;
}


int KS_combo(n,M)
{
	printf("%d    %d\n",n,M);
	
	if (M==0)
	return 1;
	if(n<0)
	return 0;
	if(arr[n]>M)
		return KS(n-1,M);
	else
		return KS(n-1,M)+KS(n-2,M-arr[n]);
}

int KS(n,M)
{
//printf("mem value    %d\n",mem[n][M]);
	
//	printf("%d    %d\n",n,M);
	if (M==0)
	return 0;
	if(n<0)
	return 0;
	if(mem[n][M]==0)
	{
	if(arr[n]>M)
		return mem[n][M]=KS(n-1,M);
	else
		return mem[n][M]=max(KS(n-1,M),arr[n]+KS(n-2,M-arr[n]));
}
else
	{
	//printf("mem = %d  \n",mem[n][M]);
	return mem[n][M];
}
}



int main()
{
	int t,n,k,i,c=0;
	//int arr[1002];
	scanf("%d",&t);
	memset(mem,0,sizeof(mem));
	while(t--)
	{
	c++;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int i=KS(n-1,k);
	printf("Scenario #%d: %d\n",c,i);
}
	return 0;
}
