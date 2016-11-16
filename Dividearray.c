#include<stdio.h>
//int arr[] = {10,22,33, 41, 50, 60,80,130};

//int arr[]={50, 10, 20, 30, 40};

//int arr[]={21 ,45 ,30 ,12, 14 };

//int n = sizeof(arr)/sizeof(arr[0]);


int min(int a, int b)
{
    return (a < b)? a : b;
}

int fun(s1,s2)
{
	if(s1 == 0 && s2 == 0)
		return 0;
	if(s1 == 0)
		return arr[s2];
	if(s2==0)
		return arr[s1];
	int l=arr[s1]+fun(s1-1,s2);
	int r=arr[s2]+fun(s1,s2-1);
	
	return min(l,r)
}
