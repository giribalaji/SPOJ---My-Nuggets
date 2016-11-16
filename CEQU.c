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
	int t=1,x,y,z,ans,b;
	
	scanf("%d",&b);
 
 while(t<=b)
 {
 	int a;
	 scanf("%d %d %d",&x,&y,&z);
 	ans=gcd(x,y);
	 a=z%ans;
 	 if(!a)
	 printf("Case %d: Yes\n",t);
 	 else
 	 printf("Case %d: No\n",t);
 	t++;
 }
	return 0;
}
