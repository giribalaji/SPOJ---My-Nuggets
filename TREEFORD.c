#include<stdio.h>

static int c;
int temp[8010];


int search(int arr[], int x, int n)
{
    int i;
	for ( i = 0; i < n; i++)
      if (arr[i] == x)
         return i;
    return -1;
}

void form(int in[],int pre[],int n)
{
	int root=search(in,pre[0],n);
	
	if(root!=0 && root != -1)
	{
		 form(in,pre+1,root);
	}
	if(root != n-1 && root != -1)
	{
		form(in+root+1,pre+root+1,n-root-1);
	}
	temp[c++]=pre[0];
}

int main()
{

	int n;
	scanf("%d",&n);
	int pre[n+2],in[n+2],post[n+2];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	
		for(i=0;i<n;i++)
	{
		scanf("%d",&post[i]);
	}
		for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	
	form(in,pre,n);
	int f=1;
	for(i=0;i<n;i++)
	{
		if(temp[i]!=post[i])
		{
			f=0;
			break;
		}
		//printf("%d ",temp[i]);
	}

	if(f)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}
