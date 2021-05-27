#include<bits/stdc++.h>
using namespace std;
//int 
bool mycomp(const pair<int,int> a,
                   const pair<int,int> b)
{
       if(a.second == b.second){
return a.first > b.first;
}
return a.second > b.second;
}

int main(){
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	vector< pair<int,int> > v;
	int vf,mx_price,mx_dist;
	cin>>vf>>mx_price>>mx_dist;
	for(int i=0;i<n;i++){
		if(vf == 1){
		    if(a[i][2] == vf && a[i][3] <= mx_price && a[i][4] <= mx_dist){
//		    	vector<int> v1;
				v.push_back(make_pair(a[i][0],a[i][1]));
//				v.push_back(v1);			
		    }
		}
	    else if(vf == 0 && a[i][3] <= mx_price && a[i][4] <= mx_dist){
//	    	vector<int> v1;
	    	v.push_back(make_pair(a[i][0],a[i][1]));
//			v1.push_back(a[i][0]);
//			v1.push_back(a[i][1]);
//			v.push_back(v1);			
	    }
	}
	sort(v.begin(), v.end(), mycomp);
	vector<int> ans;
	for(int i=0;i<v.size();i++)
	ans.push_back(v[i].first);
//	sort(v.begin(),v.end(),mycomp);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
}
//5
//1 4 1 40 10
//2 8 0 50 5
//3 8 1 30 4
//4 10 0 10 3
//5 1 1 15 1
