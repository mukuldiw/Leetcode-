#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> v;
	int j = 0, r = n-1, count = 0,i = n-1,res = 0;
	while(i >= 0){
		if(a[i] == 0){
			count++;
			v.push_back(i);
		}
		if(count == k+1){
			if(j < v.size()){
				r = v[j] - 1;
				j++;
				count--;
			}
		}
		res = max(res,r-i+1);
		i--;
	}
	cout<<res;
//	for(int j=0;j<v.size();j++)cout<<v[j]<<" ";
}
//19 3
//0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1
