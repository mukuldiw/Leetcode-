#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int *dp = new int[n];
	for(int i=0;i<n;i++)
	dp[i] = 0;
	dp[n-1] = 0;
	dp[n-2] = 1;
	for(int i=n-3;i>=0;i--){
		if(a[i] == 0){
			dp[i] = INT_MAX;
			continue;
		}
		if(i + a[i] >= n-1)
		dp[i] = 1;
		else{
			int min = INT_MAX;
			for(int j = i+1;j<=i+a[i];j++){
				if(dp[j] < min)
				min = dp[j];
				dp[i] = min + 1;
			}
		}
	}
	for(int i=0;i<n;i++)
	cout<<dp[i]<<" ";
}

