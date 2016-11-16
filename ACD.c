#include<stdio.h>
char s[120];
void print(char *p,int flag,int i)
{
	if(*p=='\0')
	{
		
		s[i]='\0';
		printf("%s\n",s);
		return;
	}
	if(flag==1)
	{
	//	printf("%c\n",*p);
		s[i]=*p;
		print(p,0,i+1);
		print(p+1,1,i+1);
	}
	if(flag==0&&*(p+1)!='\0')
	{
	//	printf("_\n");
		s[i]='_';
		print(p+1,1,i+1);
	}
}
int main(void)
{
	
	print("ABCDEF",1,0);
	return 0;
}
