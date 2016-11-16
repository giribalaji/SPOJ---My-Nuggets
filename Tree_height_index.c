#include<stdio.h>
  
int len;
int mem[400]={0};
int depth_fun(int arr[],int p)
{
	if(mem[p+1]==0)
	{
	
	printf("Parent is %d\n",p);
	int max_depth=0,i,depth;
	for(i=0;i<len;i++)
	{
		printf("i value is %d for paren %d\n",i,p);
		if(p==arr[i])
		{
			
			depth=1+depth_fun(arr,i);
			if(max_depth < depth)
				max_depth=depth;
		}
}
	return mem[p+1]=max_depth;
}
else
return mem[p+1];
}




int main()
{
	int arr[]={3,3,3,-1,2,1};
	len=sizeof(arr)/sizeof(int);
	printf("%d\n",depth_fun(arr,-1));

return 0;
}  




