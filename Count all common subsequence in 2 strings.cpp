#include <bits/stdc++.h>
using namespace std;
void CommomSubsequencesCount(string s, string t)
{
	int n1 = s.length();
	int n2 = t.length();
	int dp[n1+1][n2+1];

	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			dp[i][j] = 0;
		}
	}
	
	for (int i = 1; i <= n1; i++) {

		for (int j = 1; j <= n2; j++) {

			if (s[i - 1] == t[j - 1])
				dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j];		
			else
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j] -
										dp[i - 1][j - 1];		
		}
	}

	for (int i = 0; i <= n1; i++) {

		for (int j = 0; j <= n2; j++) {
			cout<<dp[i][j]<<" ";
			}
		cout<<endl;
		}
}

int main()
{
	string s,t;
	cin>>s>>t;
	CommomSubsequencesCount(s, t);
	return 0;
}

