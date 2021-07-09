#include<bits/stdc++.h>
using namespace std;

int dfs(int **a,int **dp,int i,int j,int n){
	
	if( i < 0 || i >= n || j < 0 || j >= n) return 0;
	if(dp[i][j] != 0)return dp[i][j];
	
	int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;
	if(dp[i][j] == 0){
		if (j < n - 1 && ((a[i][j] + 1) == a[i+1][j + 1]) && i<n-1)
	        x = dp[i][j] + dfs( a, dp,i+1, j + 1,n);
	
	    if (j > 0 && (a[i][j] + 1 == a[i+1][j - 1]) && i<n-1)
	        y = dp[i][j] + dfs( a, dp,i, j - 1,n);
	
//	    if (i > 0 && (a[i][j] + 1 == a[i - 1][j]))
//	        z = 1 + dfs( a, dp,i - 1, j,n);
	
	    if (i < n - 1 && (a[i][j] + 1 == a[i + 1][j]))
	        w = dp[i][j] + dfs( a, dp,i + 1, j,n);
	    }
	
	dp[i][j] = max(x, max(y, max(z, max(w, 1))));
	return dp[i][j];
}
int main(){
	int n;cin>>n;
	int **a = new int*[n];
	for(int i=0;i<n;i++)a[i] = new int[n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	int **dp = new int*[n];
	for(int i=0;i<n;i++)dp[i] = new int[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = 0;
		}
	}
	int ans = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dp[i][j] == 0)
				dfs(a,dp,i,j,n);
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
}

