#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,x;
	cin>>s>>x;

	int n = s.length(),m = x.length(),ans=0;
	
	int **dp = new int*[n+1];
	for(int i=0;i<n+1;i++)dp[i] = new int[m+1];
	
	int l=0,r=0;
	
	for(int i=0;i<n+1;i++){
		for(int j = 0;j<m+1;j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i=0;i<n+1;i++){
		for(int j = 0;j<m+1;j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}
			if(s[i-1] == x[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				if(dp[i][j] > ans){
					l = i;r=j;
					ans = dp[i][j];
				}
			}
		}
	}
	
	int c = 0;
	string str="";
	while(c < ans){
		str = str + x[r-1];
		r--;
		c++;
	}
	reverse(str.begin(),str.end());
	cout<<str<<"  "<<ans;
}


