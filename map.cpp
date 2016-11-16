#include <iostream>       // std::cout
#include <stack> 
#include <string>        // std::stack
#include<map>
#include<stdio.h>
using namespace std;


int count(int h)
{
	int n=h;
	int cnt=0;
	while(n>0)
	{
		n=n/10;
		cnt++;
	}
return cnt;
}


int main()
{
	map<long long int,char> cl;
	int i=1000000000;
	cl[i]='s';
	cl[9000000000]='e';
	cout<<cl[i]<<endl<<cl['e']<<endl;
	 
	cout<<i<<endl;
	int k=9,l=5;
//	printf("%0%dd\n",k,l);
	
	char buf[9]={0};
	//buf[8]='\0';
	int num=123;
	int c=count(123);
	printf("%d\n",c);
	//int r=snprintf(buf+(8-c),c,"%d",num);
	sprintf(buf,"%s","00000000");
	int r=sprintf(buf+(8-c),"%d",num);
    printf("%s %d\n",buf,r);
    puts(buf);
	return 0;
}
