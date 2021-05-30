#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string x = s;
	reverse(x.begin(),x.end());
	cout<<x<<endl;
	int n = s.length();
	int **dp = new int*[n + 1];
	for(int i=0;i<=n;i++)
	dp[i] = new int[n + 1];
	
	for(int i=0;i<=n;i++){
		for(int j = 0; j<=n;j++){
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
	cout<<dp[n][n];			
}

