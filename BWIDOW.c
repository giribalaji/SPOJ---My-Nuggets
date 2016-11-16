#include<stdio.h>

int main()
{
 int t,n,in,out,li,lo,ans,i;
 
 scanf("%d",&t);
 
 while(t--)
 {
 	ans=0,li=0;lo=0,ans=-1;
	 scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 	scanf("%d %d",&in,&out);	
 	if(out>li && out > lo && in > lo)
 	{
 		li=in;
 		lo=out;
 		ans=i+1;
  	}
  	else if(out > li && in <=lo)
  	  	{
  		ans=-1;
  		li=in;
  		lo=out;
  	}
 	else if (out == li)
 	{
 		ans=-1;
 	}
 	
 	}
 
 printf("%d\n",ans);
 }

	return 0;
}
