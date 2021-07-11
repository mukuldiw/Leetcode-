#include<bits/stdc++.h>
using namespace std;
int minASCIIsubseq(string s,string x){
	int m =s.length(),n = x.length();
	
	int dp[m + 1][n + 1]; 
	    int i, j; 
	 
	for (i = 0; i <= m; i++){ 
	    for (j = 0; j <= n; j++) 
	    { 
		    if (i == 0 || j == 0) 
		       dp[i][j] = 0; 
		      
		    else if (s[i - 1] == x[j - 1]) 
		        dp[i][j] = dp[i - 1][j - 1] + int(s[i-1]); 
		      
		    else
	    	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
	    } 
	} 
	int r1=0;
	for(int i=0;i<m;i++)r1+=int(s[i]);
	for(int i=0;i<n;i++)r1+=int(x[i]);
	
	return r1 - 2*dp[m][n];
	
}
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
}
int main(){
	string s,x;
	cin>>s>>x;
	cout<<minASCIIsubseq(s,x);
}

