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
			if(recStack[*it])
			return 1;
			if(!visited[*it] && detectCycleHelper(*it,visited,recStack))
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
    return detectCycleHelper(0, visited, recStack);
//    for(int i = 0; i < V; i++)
//        if (detectCycleHelper(i, visited, recStack))
//            return true;
// 
//    return false;
}
int main()
{
    int n,e;cin>>n>>e;
    Graph g(n);
    for(int i=0;i<e;i++){
    	int x,y;cin>>x>>y;
    	g.addEdge(x,y);
    	g.addEdge(y,x);
	}
    cout<<g.detectCycle();
 
    return 0;
}
