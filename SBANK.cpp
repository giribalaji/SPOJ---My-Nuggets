#include <iostream>       // std::cout
#include <stack> 
#include <string>        // std::stack
#include<map>
#include<stdio.h>
using namespace std;

int main()
{
int t;
scanf("%d",&t);

while(t--)
{
	
	map<string,int> mp;
	map<string,int>::iterator it;
	char st[40];
	int n=0;
	//string st;
	scanf("%d",&n);
//	cin>>n;
	while(n)
	{
		//getline(cin,st);
		gets(st);
//		cout<<st<<'\t'<<n<<endl;
		mp[(string)st]++;
	    n--;
	}
	
	
	for(it=mp.begin();it!=mp.end();++it)
		{
			cout<<(*it).first<<" "<<(*it).second<<endl;
		}
	//cout<<cl[i]<<endl<<cl['e']<<endl;
	printf("\n"); 
}	
	return 0;
}
