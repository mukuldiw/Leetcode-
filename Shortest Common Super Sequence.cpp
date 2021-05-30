#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,x;
	cin>>s>>x;
	int n = s.length(),m = x.length();
	int **dp = new int*[n+1];
	for(int i=0;i<n+1;i++)
	dp[i] = new int[m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i == 0 || j == 0)
			dp[i][j] = 0;
			else if(s[i-1] == x[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int ans = n - dp[n][m];
	ans = ans + m - dp[n][m];
	cout<<ans + dp[n][m];
}

