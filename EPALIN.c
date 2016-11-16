#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lps[200005];

char* strrev(char *p)
{
	char *s,*e,t;
	if(!p || ! *p)
		return p;
	s=p;e=p+(strlen(p)-1);
	while(s<e)
	{
		t=*s;
		*s=*e;
		*e=t;
		s++;
		e--;
	}
	return p;
	
}

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
	char arr[200005];
	char *m=arr;
	char st[200005];
	char *p=st;
	char tmp[100005];
	char *t=tmp;
	int z;
	while(scanf("%s",m)!= EOF)
	{
	
	
	strcpy(t,m);
	char *t1=strrev(t);
//	printf("%s\n",t1);
	strcpy(p,t1);
	strcat(p,"#");
	strcat(p,m);
//	printf("%s\n",p);
	KMP(p,strlen(p));
//	printf("Str len=%d\n",strlen(p));
	
	int i;
	for(i=0;i<strlen(p);i++)
	{
//		printf("%d\t",lps[i]);
	}

	//if()
	strcat(m,t1+lps[strlen(p)-1]);
	printf("%s\n",m);
	memset(lps,0,sizeof(lps));
//	printf("\n");
	}return 0;
	
}
