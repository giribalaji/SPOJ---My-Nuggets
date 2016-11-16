#include<stdio.h>

int main()
{
 int t,n;
 
 scanf("%d",&t);
 
 while(t--)
 {
 	int sum =0,ans1=0,ans2=0,psum=0,i;
	 scanf("%d",&n);
	 for(i=1;sum<n;i++)
	 {
	 	psum=sum;
		 sum=sum+i;
	 }
	i=i-1;	 
	
//printf("Answer is %d  for sum = %d previous sum = %d\n",i,sum,psum);
	
	 if(i%2)
	 {
	 
	 	ans1=sum-n+1;
		ans2=n-psum;
}
	else
{

		ans2=sum-n+1;
		ans1=n-psum;	
}

printf("TERM %d IS %d/%d\n",n,ans1,ans2);
}
	
	 return 0;
}

