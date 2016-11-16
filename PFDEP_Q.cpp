#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
#define MAX 105

int visited[MAX];
using namespace std;

vector<vector <int> >adj;
//stack<int> st;

queue<int> st;



void DFS_toposort(int Start)
{

     if(visited[Start])
        return;
    vector<int>::iterator i;
  
        int top =Start;
       // cout << top << " ";
        visited[top] = 1;
        for(i = adj[top].begin(); i != adj[top].end(); i++)
        {
       //   cout << visited[*i] << " "<<*i<<endl; 
	//		if (!visited[*i])
      //      {
     	//		 cout << *i << " ";      
   //          cout << Start << " "<<visited[*i] << " "<<*i<<endl;
			    DFS_toposort(*i);
   // }
		}
    //if(!visited[Start])
	st.push(Start);
    //cout << endl;
}



int main()
{
while(1)
{

int temp[MAX];
memset(visited,0,sizeof(visited[0])*MAX);
memset(temp,0,sizeof(temp[0])*MAX);
int n,e,i,j,t1,t2,q,u,v;
//printf("Enter number of nodes/Vertices:");
scanf("%d %d",&n,&q);
adj=vector<vector<int> >(n+5);
for(i=0;i<q;i++)
{
	scanf("%d %d",&v,&t1);
	temp[v]=1;
	for(j=0;j<t1;j++)
	{
	scanf("%d",&u);
		
	adj[v].push_back(u);
	//adj[t2].push_back(t1);
}
}


	for(i=1;i<=n;i++)
	{
	//cout << visited[i] << " ";
	if(!visited[i])
	{
	
	DFS_toposort(i);
}}

while(!st.empty())
{
	cout<<st.front()<<" ";
	st.pop();
	
}



cout << endl;

}

	return 0;
}
