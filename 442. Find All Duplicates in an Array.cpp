#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	vector<int> ans;
	
	for(int i=0;i<n;i++){
		a[abs(a[i])-1] = - a[abs(a[i]) - 1];
		if(a[abs(a[i]) - 1] > 0)ans.push_back(abs(a[i]));
	}
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}

