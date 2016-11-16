#include<stdio.h>
char str[1005];
char *s=str;
static int i=0;

int depth(char *s)
{
	if(!s || *s == 'l')
	{
		return 0;
	}

		if(*s=='n')
		{
			
			int ld=depth(s+1);
			int rd=depth(s+2);
			if(ld>rd)
				return ld+1;
			else
				return rd+1;
	
		
		}
	}

int depth_1()
{
	if(!(*s) || *s == 'l')
	{
		return 0;
	}

		if(*s=='n')
		{
			s++;
			int ld=depth_1();
			s++;
			int rd=depth_1();
			if(ld>rd)
				return ld+1;
			else
				return rd+1;
	
		
		}
	}

int depth_2()
{
	if(!(s[i]) || s[i] == 'l')
	{
		return 0;
	}

		if(s[i]=='n')
		{
//			printf("i= %d .. s = %c\n",i,s[i]);
			i++;
//			printf("i= %d .. s = %c\n",i,s[i]);
			int ld=depth_2();
			i++;
//			printf("i= %d .. s = %c\n",i,s[i]);
			int rd=depth_2();
			if(ld>rd)
				return ld+1;
			else
				return rd+1;
	
		
		}
	}

 

int main()
{
	int m,n,t;
//	int mg[10000]
	scanf("%d",&t);
	while(t--)
	{
	i=0;
	scanf("%s",s);
	n=depth_2();
	printf("%d\n",n);
	}
return 0;	
}
