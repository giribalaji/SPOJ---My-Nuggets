#include<stdio.h>
#include<iostream>
#include<stack>
#include <string>
using namespace std;
stack<int>s;



int main(){
int t,b=1;
	
	cin>>t;
 
 while(t--)
 {

int q,v;
//scanf("%d",q);
cin>>q;
//printf("q=%d\n",q);
if(q==1)
{
if(s.empty())
	{
		printf("No Food\n");
	}
	else
	{
		printf("%d\n",s.top());
		
			s.pop();
		}
}

if(q==2)
{
cin>>v;
	s.push(v);
}
}
return 0;
}
