#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum;
	cin>>n>>sum;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	bool **dp = new bool*[n+1];
	for(int i=0;i<n+1;i++){
		dp[i] = new bool[sum+1];
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			if(i == 0 && j!=0)
			dp[i][j] = false;
			else if(j == 0)
			dp[i][j] = true;
			else if (a[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j] || dp[i][j-a[i-1]];
			}
		}
	}
	cout<<dp[n][sum];
//	for(int i=0;i<n+1;i++){
//		for(int j=0;j<sum+1;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
}

