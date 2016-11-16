#include<stdio.h>
#include<iostream>
#include<stack>
#include <string>
#include <queue>  
using namespace std;
stack<int>s;



int main(){
queue <int> q;
int n,i=1,count=0;
cin>>n;
int arr[105];
int g;
	for(i=0;i<n;i++)
	{
	cin>>g;
		q.push(g);
	}
 
for(i=0;i<n;i++)
	{
	cin>>arr[i];
		
	}

i=0;

while(i<n)
{
	if(arr[i]==q.front())
	{
		q.pop();
		i++;
	}
	else
	{
		q.push(q.front());
		q.pop();
	}
count++;
}

printf("%d\n",count);


return 0;
}
