#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int t,n;
char *s;
scanf(“%d”,&t);
s = (char*)malloc(1000);

while(t–)
{

scanf(“%d %s”,&n,s);
n=strlen(s)-1;
printf(“%c\n”,s[n]);
}
return 0;
}
