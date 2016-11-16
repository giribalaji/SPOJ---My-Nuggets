#include<stdio.h>


int gcd(int a,int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}

int main()
{
	int t,x,y,ans;
	
	scanf("%d",&t);
 
 while(t--)
 {
 	int a,b;
	 scanf("%d %d",&x,&y);
 	ans=gcd(x,y);
	 a=y/ans;
 	b=x/ans;
	 printf("%d %d\n",a,b);
 }
	return 0;
}
