#include<stdio.h>

int main()
{
 int t,n,in,max_in,out[1010],index,ans,flag,i;
 
 scanf("%d",&t);
 
 while(t--)
 {
 	max_in=0,ans=-1,flag=1;
	 scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 	scanf("%d %d",&in,&out[i]);	
 	if(in>max_in)
 	{
 		max_in=in;
 		index=i;
 	}
 	}
	 
	 for(i=0;i<n;i++)
 	{
	 if(i!=index && out[i]>max_in )
	 {
	 	 flag=0;
	     break;
	 }
	  	}
 
 if(flag)
  printf("%d\n",index+1);
else
	printf("%d\n",ans);
 }

	return 0;
}
