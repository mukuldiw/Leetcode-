#include<bits/stdc++.h>
using namespace std;
struct val{
	int first;
	int second;
};
bool comp(val a,val b){
	return a.second < b.second;
}
int main(){
	int n;
	cin>>n;
	struct val p[n];
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
	}
	sort(p,p+n,comp);
	int *dp = new int[n];
	for(int i=0;i<n;i++)
	dp[i] = 1;
	int a,b,max=1;
	for(int i=n-2;i>=0;i--){
		a = p[i].first;
		b = p[i].second;
		int count=0;
		for(int j=i+1;j<n;j++){
			if(p[j].first > b){
				if(count < dp[j]){
					count = dp[j];
				}
			}
			dp[i] = count + 1;
			if(dp[i] > max)
			max = dp[i];
		}
	}
	for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl<<max;
}
//5
//5 24
//15 28
//27 40
//39 60
//50 90

