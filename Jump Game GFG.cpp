#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];for(int i=0;i<n;i++)cin>>a[i];
	int dp[n] = {0};
	dp[n-1]=1;
	int ind = n-1;
	for(int i=n-2;i>=0;i--){
		if(i + a[i] >= ind){
			dp[i] = 1;
			ind = i;
		}
	}
	for(int i=0;i<n;i++)cout<<dp[i]<<" ";
}

