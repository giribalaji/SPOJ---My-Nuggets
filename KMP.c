#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lps[50000];


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
	char arr[5000];
	char *m=arr;

	while(1)
	{
	
	scanf("%s",m);
	KMP(m,strlen(m));
	printf("Str len=%d\n",strlen(m));
	
	int i;
	for(i=0;i<strlen(m);i++)
	{
		printf("%d\t",lps[i]);
	}
	memset(lps,0,sizeof(lps));
	printf("\n");
	}return 0;
	
}
