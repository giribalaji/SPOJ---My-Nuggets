#include<stdio.h>
  
int len;

int depth(int arr[],int p)
{
	int max_depth=0,i,depth;
	for(i=0;i<len;i++)
		if(p==arr[i])
		{
			depth=1+depth(arr[],i);
			if(max_depth < depth)
				max_depth=depth;
		}
	return max_depth;
}




inr main()
{
	int arr[]={2,3,-1,1,2,4};
	len=sizeof(arr)/sizeof(int);
	printf("%d\n",depth(arr,-1));

return 0;
}  




