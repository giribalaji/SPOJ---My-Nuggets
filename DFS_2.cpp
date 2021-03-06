#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
private:
    int num_of_vertices;
    vector<int> *Adj;
public:
    Graph(int V);
    void addEdge(int from, int to);
    void BFS(int Start);
    void DFS(int Start);
    void DFS_toposort(int Start, int tot);
};

Graph::Graph(int V)
{
    this->num_of_vertices = V;
    Adj = new vector<int>[V];
}
void Graph::addEdge(int from, int to)
{
    Adj[from].push_back(to);
}

void Graph::BFS(int Start)
{
    bool* visited = new bool[this->num_of_vertices]();
    queue<int> queue;
    queue.push(Start);
    vector<int>::iterator i;
    cout << "BFS: ";
    while(!queue.empty())
    {
        Start = queue.front();  
        cout << Start << " ";
        visited[Start] = true;
        queue.pop();
        for (i = Adj[Start].begin(); i != Adj[Start].end(); i++)
        {
            if (!visited[*i])
                queue.push(*i);
        }
    }
    cout << endl;
}

void Graph::DFS(int Start)
{
    bool* visited = new bool[this->num_of_vertices]();
    stack<int> stack,temp;
    stack.push(Start);
    temp.push(Start);
    vector<int>::iterator i;
    cout << "DFS: ";
    while(!stack.empty())
    {
        int top = stack.top();
        cout << top << " ";
        stack.pop();
        visited[top] = true;
        for(i = Adj[top].begin(); i != Adj[top].end(); i++)
        {
            if (!visited[*i])
                stack.push(*i);
        
		}
    	temp.push(top);
	}
    cout << endl;

cout << "DFS: topo ";

while(!temp.empty())
{
	cout<<temp.top()<<" ";
	temp.pop();
}
}

/*void Graph::DFS_toposort(int Start,int tot)
{
    bool* visited = new bool[this->num_of_vertices]();
    stack<int> stack;
     vector<int>::iterator i;
    cout << "DFS: ";
   int i,j;
    for(i=0;i<tot;i++)
        {
    		stack.push();	
    	
    }
	while(!stack.empty())
    {
        int top = stack.top();
        cout << top << " ";
        stack.pop();
        visited[top] = true;
        for(i = Adj[top].begin(); i != Adj[top].end(); i++)
        {
            if (!visited[*i])
                stack.push(*i);
        }
    }
    cout << endl;
}*/



int main()
{
	// Create a graph given in the above diagram
/*	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);*/


/*Graph g(9);
    g.addEdge(1, 2); g.addEdge(1, 3); g.addEdge(1, 4);
    g.addEdge(2, 5); g.addEdge(2, 6); g.addEdge(4, 7);
    g.addEdge(4, 8);*/

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
	cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
	g.DFS(5);


	return 0;
}
