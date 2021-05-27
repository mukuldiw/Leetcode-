#include <bits/stdc++.h>
using namespace std;
#define N 100000

vector<int> gr1[N], gr2[N];
  
bool vis1[N], vis2[N];

void Add_edge(int u, int v)
{
    gr1[u].push_back(v);
    gr2[v].push_back(u);
}
int deg(int n){
	for(int i=1;i<=n;i++){
		if(gr1[i].size() %2 != 0)
		return 0;
		if(gr2[i].size() %2 != 0)
		return 0;
	}
	return 1;
}

void dfs1(int x)
{
    vis1[x] = true;
  	vector<int>::iterator it;
    for (it=gr1[x].begin();it!=gr1[x].end();++it)
        if (!vis1[*it])
            dfs1(*it);
}
  
// DFS function
void dfs2(int x)
{
    vis2[x] = true;
  
    vector<int>::iterator it;
    for (it=gr2[x].begin();it!=gr2[x].end();++it)
        if (!vis2[*it])
            dfs2(*it);
}
  
bool Is_Connected(int n)
{
    // Call for correct direction
    memset(vis1, false, sizeof vis1);
    dfs1(1);
  
    // Call for reverse direction
    memset(vis2, false, sizeof vis2);
    dfs2(1);
  
    for (int i = 1; i <= n; i++) {

        if (!vis1[i] and !vis2[i])
            return false;
    }

    return true;
}

int main()
{
    int n = 4;
  
    Add_edge(1, 2);
    Add_edge(2, 1);
    Add_edge(1, 3);
    Add_edge(3, 1);
//    Add_edge(2, 3);
//    Add_edge(3, 2);
    Add_edge(3, 4);
    Add_edge(4,3);
    Add_edge(4, 2);
    Add_edge(2, 4);

    if (Is_Connected(n))
        {
        	if(deg(n)){
        		cout<<"2";
			}
			else
			cout<<"1";
		}
    else
        cout << "0";
  
    return 0;
}
