#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
#define MAX 105

int visited[MAX];
using namespace std;
vector<vector <int> >adj;
int temp[MAX];
//stack<int> st;

stack<int> st;




void DFS_toposort(int k)
{

	visited[k]=1;
	st.push(k);
	int t;
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
		}
		
	}
	
}


int main()
{

int t;
scanf("%d",&t);
while(t--)
{

memset(visited,0,sizeof(visited[0])*MAX);
int n,e,i,j,t1,t2,q,u,v;
//printf("Enter number of nodes/Vertices:");
int c=0;
scanf("%d %d",&n,&q);
adj=vector<vector<int> >(n+5);
for(i=0;i<q;i++)
{
	scanf("%d %d",&v,&u);

		
	adj[u].push_back(v);
	
	adj[v].push_back(u);
}



	for(i=0;i<n;i++)
	{
	//cout << visited[i] << " ";
	if(!visited[i])
	{
	c++;
	DFS_toposort(i);
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
