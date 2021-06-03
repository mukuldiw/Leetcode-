#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,x;
	cin>>s;
	int n = s.length(),m = s.length();
	int **dp = new int*[n+1];
	for(int i=0;i<n+1;i++)
	dp[i] = new int[m+1];
	string ans="";
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j] = 0;
		}
	}
	int max =0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[j-1] == s[i-1] ){
				dp[i][j] = dp[i-1][j-1] + 1;
				if(dp[i][j] > max)
				max = dp[i][j];
			}                                                  
			else{
				dp[i][j] = dp[i][j] + dp[i][j-1];
			}
		}
	}
//	cout<<max;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}
