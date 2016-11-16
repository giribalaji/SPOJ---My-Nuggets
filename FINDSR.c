#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lps[100006];


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
	char arr[100006];
	char *m=arr;
	scanf("%s",m);
	while(m[0]!='*')
	{
	
	KMP(m,strlen(m));
	//printf("Str len=%d\n",strlen(m));
	
	int i;
/*	for(i=0;i<strlen(m);i++)
	{
		printf("%d\t",lps[i]);
	}*/

	int n=strlen(m);
	if(n%(n-lps[n-1]))
	{
		printf("1\n");
	}
	else
	{
		printf("%d\n",n/(n-lps[n-1]));
	}
	memset(lps,0,sizeof(lps));
		
	scanf("%s",m);
	}return 0;
	
}
