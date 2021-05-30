#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum;
	cin>>n>>sum;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int **dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	dp[i] = new int[sum+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i == 0 && j!=0)
			dp[i][j] = 0;
			else if(j == 0){
				dp[i][j] = 1;
			}
			else if(a[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
			}
		}
	}
	cout<<"No of Subsets with sum: "<<sum<<" are "<<dp[n][sum];
}
