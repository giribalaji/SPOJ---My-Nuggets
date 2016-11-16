#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
#define MAX 105

int visited[MAX];
using namespace std;
vector<vector <int> >adj;
vector <int> vt;
int temp[MAX];
int ed[MAX][MAX];
//stack<int> st;

stack<int> st;


/*void fun()
{
	int k=vt[0],t,i,j;
	for(i=0;i<vt.size();i++)
{
//	cout<<vt[i]<<" ";

}
cout<<endl;
	for(i=0;i<vt.size()-1;i++)
	{
	for(j=i+1;j<vt.size();j++)
	{
	
	
		if(vt[j]<vt[i]&&ed[vt[i]][vt[j]]==0)
		{
//	cout<<vt[i]<<" "<<vt[j]<<" "<<ed[vt[i]][vt[j]]<<endl;
			t=vt[i];
			vt[i]=vt[j];
			vt[j]=t;
//cout<<vt[i]<<" "<<vt[j]<<" "<<ed[vt[i]][vt[j]]<<endl;
		}
	}
cout<<endl;	
	}
}*/

void fun()
{
	int k=vt[0],t,i,j,flag=1;
	for(i=0;i<vt.size();i++)
{
	cout<<vt[i]<<" ";

}
cout<<endl;
	for(i=1;i<vt.size();i++)
	{
		if(vt[i]<vt[i-1]&&ed[vt[i]][vt[i-1]]==0)
		{
			j=i+1;
			if(j>=vt.size())
				flag=1;
			if(j<vt.size()&&ed[vt[i-1]][vt[j]]==1&&ed[vt[i]][vt[j]]==1)
				flag=0;
			if(flag)
			{
			
			t=vt[i-1];
			vt[i-1]=vt[i];
			vt[i]=t;
		}
		}
	}
}



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
           //  cout << Start << " "<<visited[*i] << " "<<*i<<endl;
			    DFS_toposort(*i);
   // }
		}
    //if(!visited[Start])
	vt.insert(vt.begin(),Start);
	fun();
    //cout << endl;
}



int main()
{
while(1)
{
memset(ed,0,sizeof(ed[0][0])*MAX*MAX);
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
		
	adj[u].push_back(v);
	ed[u][v]=1;
	ed[v][u]=1;
	//adj[t2].push_back(t1);
}
}


	for(i=1;i<=n;i++)
	{
	//cout << visited[i] << " ";
	if(!visited[i]&&adj[i].size()!=0)
	{
//	cout<<"size = "<<adj[i].size()<<endl;
	DFS_toposort(i);
}}

/*while(!st.empty())
{
	cout<<st.top()<<" ";
	st.pop();
	
}*/
fun();
for(i=1;i<=n;i++)
{
	if(!visited[i])
	{
		vt.insert(vt.begin(),i);
	fun();
	}
}


for(i=0;i<n;i++)
{
	cout<<vt[i]<<" ";
}

cout << endl;

vt.erase(vt.begin(),vt.end());
}
	return 0;
}
