#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector> 
#include<iterator>
#include<map>    
#include<list>   
#define MAX 106   
#include  <queue>
using namespace std;

typedef pair <int, pair<int,int> > ct;
ct c;

int main()
{
	c.first=9;
	c.second.first=10;
	c.second.second=11;
	cout<<c.first<<" "<<c.second.first<<" "<<c.second.second;
	
	return 0;
}
