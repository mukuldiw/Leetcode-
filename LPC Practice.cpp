#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	cin>>s;
	t = s;
	reverse(t.begin(),t.end());
	int n = s.length(),m=t.length();
	int **dp = new int*[n+1];
	for(int i=0;i<n+1;i++)dp[i] = new int[m+1];
	
	int ans = 0;
	string str = "";
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}
			if(s[j-1] == t[i-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
//				ans = max(ans,dp[i][j]);
				if(dp[i][j] >= ans){
					ans = dp[i][j];
					str = s.substr(j-ans,ans);
				}
				
			}
			else{
				dp[i][j] = 0;
			}
		}
	}
	cout<<ans<<" "<<str;
}

