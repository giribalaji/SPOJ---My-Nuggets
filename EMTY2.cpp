#include<stdio.h>
#include<iostream>
#include<stack>
#include <string>
using namespace std;
stack<char>s;

void fun( char r)
{
	int flag=1;
	char *arr=new char[3];
	char pre;
//	string arr;
	char cur='0';
	int count=1;
	/*if(s.empty())
	{
		flag=1;
	}*/
	
	while(!s.empty()&&count <= 2)
	{
		if(s.top()!=cur)
		{
			flag=count;
			break;
		}
		
		
		arr[count-1]=s.top();
		s.pop();
		count++;
		cur='1';
		
		
		if(count==2)
		{
			flag=3;
		}
	}

	if(flag==1)
	{
		s.push(r);
	}
	else if(flag == 2)
	{
		s.push(arr[0]);
		s.push(r);
	}
}


int main(){
int t,b=1;
	
	cin>>t;
 
 while(b<=t)
 {
//stack<char>s;
string in;
cin>>in;
int i;
for(i=0;i<in.length();i++)
{
	if(in[i]=='1')
	{
		s.push(in[i]);
	}
	else
	{
		fun(in[i]);
	}
}

if(s.empty())
	{
		printf("Case %d: yes\n",b);
	}
	else
	{
		printf("Case %d: no\n",b);
		while(!s.empty())
		{
			s.pop();
		}
	}
b++;

}
return 0;
}
