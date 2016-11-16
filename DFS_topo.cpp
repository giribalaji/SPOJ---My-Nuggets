#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <stack>
#define MAX 100

int visited[MAX];
using namespace std;
vector <int> adj[MAX];
//stack<int> st;

queue<int> st;

void DFS(int Start)
{
    stack<int> stack;
    stack.push(Start);
    vector<int>::iterator i;
    cout << "DFS: ";
    while(!stack.empty())
    {
        int top = stack.top();
        cout << top << " ";
        stack.pop();
        visited[top] = true;
        for(i = adj[top].begin(); i != adj[top].end(); i++)
        {
            if (!visited[*i])
                stack.push(*i);
        }
    }
    cout << endl;
}

void DFS_toposort(int Start)
{
 //   bool* visited = new bool[this->num_of_vertices]();
    
    
    vector<int>::iterator i;
  //  cout << "DFS: ";
    
        //int top = st.top();
        int top =Start;
       // cout << top << " ";
        visited[top] = 1;
        for(i = adj[top].begin(); i != adj[top].end(); i++)
        {
          cout << visited[*i] << " "<<*i<<endl; 
			if (!visited[*i])
            {
     	//		 cout << *i << " ";      
             visited[*i] =1;
			    st.push(*i);
    }
		}
    //if(!visited[Start])
	st.push(Start);
    //cout << endl;
}



int main()
{
memset(visited,0,sizeof(visited[0])*MAX);
int n,e,i,j,t1,t2;
/*printf("Enter number of nodes/Vertices:");
scanf("%d %d",&n,&e);

for(i=0;i<e;i++)
{
	scanf("%d %d",&t1,&t2);
	adj[t1].push_back(t2);
	//adj[t2].push_back(t1);
}*/

/*adj[5].push_back(2);
adj[5].push_back(0);
adj[4].push_back(0);
adj[4].push_back(1);
adj[2].push_back(3);
adj[3].push_back(1);*/
n=5;
adj[1].push_back(3);
adj[5].push_back(3);
adj[5].push_back(2);
adj[3].push_back(2);
adj[3].push_back(4);
adj[1].push_back(5);


/*adj[3].push_back(1);
adj[3].push_back(5);
adj[2].push_back(5);
adj[2].push_back(3);
adj[4].push_back(3);
adj[5].push_back(1);*/

	cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
	
	for(i=1;i<=n;i++)
	{
	//cout << visited[i] << " ";
	if(!visited[i])
	{
	
	DFS_toposort(i);
}}

cout << endl;
while(!st.empty())
{
	cout<<st.front()<<" ";
	st.pop();
}

	return 0;
}
