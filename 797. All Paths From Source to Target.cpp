#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	public:
		Graph(int d){
			this->V = d;
			adj = new list<int>[V];
		}
		void addEdge(int x,int y){
			adj[x].push_back(y);
		}
		void PathsUtil(int s,int t,int x,vector<int>,vector< vector<int> > &,int *visited);
		void paths(int s,int t);
};
void Graph::PathsUtil(int s,int t,int x,vector<int> v,vector< vector<int> > &ans,int *visited){
		visited[x] = 1;
		v.push_back(x);
		if(x == t){
			ans.push_back(v);
//			return;
		}
		else{
			list<int>::iterator it;
			for(it = adj[x].begin();it!=adj[x].end();++it){
				if(!visited[*it]){
					PathsUtil(s,t,*it,v,ans,visited);
				}
			}
		}
	visited[x] = 0;
}
void Graph::paths(int s,int t){
	int *visited = new int[V];
	for(int i=0;i<V;i++)
	visited[i] = 0;
	vector<int> v;
	vector< vector<int> > ans;
	
	PathsUtil(s,t,0,v,ans,visited);
	
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
	
	g.paths(0,3);
}

