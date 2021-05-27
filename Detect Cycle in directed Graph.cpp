#include <bits/stdc++.h>
using namespace std;
 
class Graph
{
	int V;
public:
	Graph(int n){
		this->V = n;
	}
    map<int, list<int> > adj;
 
    void addEdge(int v, int w);
    int detectCycleHelper(int v,bool*,bool*);
    int detectCycle();
    
    
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}
 
int Graph :: detectCycleHelper(int v,bool* visited,bool* recStack){
	if(visited[v] == 0){
		visited[v]=1;
		recStack[v]=1;
		list<int>::iterator it;
		for(it = adj[v].begin();it!=adj[v].end();++it){
			if(!visited[*it] && detectCycleHelper(*it,visited,recStack))
			return 1;
			if(recStack[*it])
			return 1;
		}
	}
	recStack[v]=0;
	return 0;
}
int Graph::detectCycle()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i = 0; i < V; i++)
        if (detectCycleHelper(i, visited, recStack))
            return true;
 
    return false;
}
int main()
{
    
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(5, 6);
    g.addEdge(5, 5);
    g.addEdge(6, 4);
    g.addEdge(6, 0);
    g.addEdge(5, 2);
//    g.addEdge(6, 4);
 
    cout<<g.detectCycle();
 
    return 0;
}
