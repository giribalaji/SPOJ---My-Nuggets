#include <iostream>
#include <vector>
#include <stdio.h>
#include<stdlib.h>
#include <queue>
#include <stack>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector> 
#include<iterator>
#include<map>    
#include<list>  
#define MAX 105


using namespace std;
vector<vector <int> >adj;

stack<int> st;




int DFS_toposort(int k,int visited[],int detect[])
{

	visited[k]=1;
	st.push(k);
	int t;
	detect[k]=1;
	vector<int>::iterator it;
	while(!st.empty())
	{
		t=st.top();
		st.pop();
		for(it=adj[t].begin(); it!=adj[t].end();it++)
		{
			if(!visited[*it])
			{
				st.push(*it);
				visited[*it]=1;
			}
			else if(detect[*it]==1)
			{
				cout<<"Inside :Cycle Detected \n";		
				return 1;
			}
		}
		
	}
	return 0;
}


int main()
{

int t;
scanf("%d",&t);
while(t--)
{


int n,e,i,j,t1,t2,q,u,v;
//printf("Enter number of nodes/Vertices:");
int c=0;
scanf("%d %d",&n,&q);
adj=vector<vector<int> >(n+5);
int visited[n+2];
int detect[n+2];
memset(visited,0,sizeof(visited[0])*(n+2));
for(i=0;i<q;i++)
{
	scanf("%d %d",&v,&u);

		
//	adj[u].push_back(v);
	
	adj[v].push_back(u);
}



	for(i=0;i<n;i++)
	{
	//cout << visited[i] << " ";
	memset(detect,0,sizeof(detect[0])*(n+2));
	if(!visited[i])
	{
	c++;
	if(DFS_toposort(i,visited,detect))
	 {
	 
	 cout<<"Cycle Detected \n";
		break;
}
}}

while(!st.empty())
{
//	cout<<st.top()<<" ";
	st.pop();
	
}


printf("%d\n",c);
//cout << endl;


}
	return 0;
}
