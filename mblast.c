#include<string.h>
#include<math.h>
#include<stdio.h>
int k;

int min(int a, int b,int c)
{
    if(a<b)
    	if(a<c)
    		return a;
    	else
    		return c;
    else if(b<c)
    	return b;
    else
    	return c;
}

int fun(char*s1,char*s2,int m,int n)
{
printf("%d   %d\n",m,n);
if(m<0&&n<0)
	return ;
if(m<0)
	{
//	if(n==0)
		n=n+1;
	return n*k;
}
if(n<0)
{
//	if(m==0)
		m=m+1;
	return m*k;
}
if(s1[m]==s2[n])
{
printf("here %c  %c\n",s1[m],s2[n]);

	return fun(s1,s2,m-1,n-1);
}
else
	return min(k+fun(s1,s2,m,n-1),k+fun(s1,s2,m-1,n),abs(s1[m]-s2[n])+fun(s1,s2,m-1,n-1));
	
}


int main()
{
	
	while(1)
	{
	char arr1[2005],arr2[2005];
	char*s1=arr1,*s2=arr2;
	scanf("%s",s1);
	scanf("%s",s2);
	int k1,m,n;
	scanf("%d",&k);
	m=strlen(s1),n=strlen(s2);
	printf("%d\n",fun(s1,s2,m-1,n-1));
}
	return 0;
}
