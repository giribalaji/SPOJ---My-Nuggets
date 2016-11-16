#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
#include<cstdio>
#include <deque>

using namespace std;
long int arr[1000001];

void arraysub(long int arr[],long int n,long int k)
{
	deque<int> dq(k);
	int i;
	for (i=0;i<k;i++)
	{
	
	while((!dq.empty()) && arr[i] >= arr[dq.back()])
		dq.pop_back();
	
	dq.push_back(i);
	}

	for (;i<n;i++)
	{
		cout << arr[dq.front()] << " ";
	
		while((!dq.empty()) && dq.front() <= i-k)
			dq.pop_front();
		while(!dq.empty() && arr[i] >= arr[dq.back()])
			dq.pop_back();
			
		dq.push_back(i);	
	}
	cout << arr[dq.front()];
}



int main()
{
	long int n,k,i=0;
	scanf("%ld",&n);

	for(;i<n;i++)
        {
			scanf("%ld",&arr[i]);
}
scanf("%ld",&k);
arraysub(arr,n,k);
return 0;
}

