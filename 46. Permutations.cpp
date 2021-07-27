#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> a;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	vector<vector<int> > v;
	int prev = 0,prev_size = 1;
	
	vector<int> d;
	d.push_back(a[0]);
	v.push_back(d);
	
	for(int i=1;i<n;i++){
		
		int x = a[i];
		int k = prev;
		while(k < prev_size){
			int j = 0,l = v[k].size();
			while(j <= l){
				vector<int> q;
				int y = 0;
				while(y < j){
					q.push_back(v[k][y]);
					y++;
				}
				q.push_back(x);
				while(y < l){
					q.push_back(v[k][y]);
					y++;
				}
			v.push_back(q);
			j++;
		}
			k++;
	}
		prev = prev_size;
		prev_size = v.size();
}
	vector<vector<int> > ans;
	for(int i=prev;i<prev_size;i++){
		ans.push_back(v[i]);
	}
	
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

