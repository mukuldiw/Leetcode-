#include<bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b)
    { return a.first > b.first; }
};

int main(){
	int n,k;cin>>n>>k;
	int **a = new int*[n];
	
	for(int i=0;i<n;i++){
		a[i] = new int[n];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	priority_queue <pair<int,pair<int,int> >, vector<pair<int, pair<int, int> > >, Compare > q;
	
	for(int i=0;i<n;i++){
		q.push(make_pair(a[0][i],make_pair(0,i)));
	}

	int ans;
	while(k--){
		pair<int,pair<int,int> > p = q.top();
		ans = p.first;
		int r = p.second.first,c = p.second.second;
		q.pop();
		if(r!=n-1){
			q.push(make_pair(a[r+1][c],make_pair(r+1,c)));
		}
	}
	cout<<ans;
}

