#include<iostream>
#include<map>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
	int n,a[1000];
	scanf("%d",&n);
	int i=0;
	for(;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
