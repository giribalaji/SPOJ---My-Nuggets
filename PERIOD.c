#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lps[1000006];


void KMP(char *p,int m)
{
	int i=1,len=0;
	while(i<m)
	{
		if(p[i]==p[len])
		{
			len++;
			
			lps[i]=len;
			i++;
		}
	
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	
}


int main()
{
	char arr[1000006];
	char *m=arr;
int t1,t=1;
int n,n1;
	scanf("%d",&t1);
	while(t<=t1)
	{
	scanf("%d",&n);
	scanf("%s",m);
	KMP(m,n);
	//printf("Str len=%d\n",strlen(m));
	printf("Test case #%d\n",t);
	int i;
	for(i=1;i<n;i++)
	{
		//printf("%d\t",lps[i]);
	
	if(lps[i]!=0)
	{
	
	//int n=strlen(m);
	n1=i+1;
	if(n1%(n1-lps[i])==0)
	{
		
		printf("%d %d\n",n1,n1/(n1-lps[i]));
	}
}
}
	memset(lps,0,sizeof(lps));
	t++;
	printf("\n");
	}
	return 0;
	
}
