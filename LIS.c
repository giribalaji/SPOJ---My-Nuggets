#include<stdio.h>
  
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60,80};
    //int arr[]={2,4,6,3,4,7,9,5};
    int n = sizeof(arr)/sizeof(arr[0]);
int mem[200][200]={0};

int max(int a, int b)
{
    return (a > b)? a : b;
}


int lis(int i,int j)
{

printf("%d . ...   %d \n",arr[i],arr[j]);
	if (i<0 || j>n)
	{
		return 0;
	}

if(arr[i]<arr[j])
{
	return (1+lis(i+1,j+1));
}
else
{
	return max(lis(i-1,j),lis(i,j+1));
}
}


int lis_memo(int i,int j)
{

printf("%d . ...   %d   ..  %d \n",arr[i],arr[j],mem[i][j]);
	if (i<0 || j>n)
	{
		return 0;
	}
if(mem[i][j]==0)
{

if(arr[i]<arr[j])
{
	return mem[i][j]=(1+lis_memo(i+1,j+1));
}
else
{
	return mem[i][j]=max(lis_memo(i-1,j),lis_memo(i,j+1));
}


}

else 

{
printf("%d\n",mem[i][j]);
return mem[i][j];
}
}


int main()
{
    //int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    //int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n",  lis( 0, 1 ));
    getchar();
    return 0;
}
