#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];	}
	int *dp = new int[n];
	for(int i=0;i<n;i++){
		dp[i] = 0;
	}
	dp[n-1] = a[n-1];
	int m = dp[n-1];
	for(int i=n-2;i>=0;i--){
		dp[i] = max(a[i],dp[i+1]+a[i]);
		if(m < dp[i])
		m = dp[i];
	}
	cout<<m;
}

