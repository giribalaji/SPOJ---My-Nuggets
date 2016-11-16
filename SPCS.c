#include<stdio.h>


int main()
{

int t;

scanf("%d",&t);

while(t--)
{


	char s[100005],t[100005];
	char*p=s,*q=t;
	char c;
	scanf("%s",p);
//	printf("%s\n",p);
	c=p[0];
	int i,j=0;
	for(i=1;i<strlen(p);i++)
	{
//	printf("%c\n",p[i]);
		if(p[i]!=c)
		{
			q[j]=c;
			j++;
		//	q[j]=p[i];
		//	j++;
		}
		c=p[i];
	
	}
	q[j++]=c;
	q[j]='\0';
//	printf("%s\n",q);

//printf("%d\n",strlen(q)-1);
int st=0,e=strlen(q)-1;
int flag=1;

//printf("%d\n",e);
for(;st<e;st++,e--)
{
	if(q[st]!=q[e])
	{
		flag=0;
		break;
	}
}

if(flag)
	printf("YES\n");
else
	printf("NO\n");


}


	return 0;
}
