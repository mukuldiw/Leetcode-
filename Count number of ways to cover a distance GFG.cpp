#include<iostream>
using namespace std;
int fn(int n){
	int dp[n];
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	if(n < 3)return dp[n-1];
	for(int i=3;i<n;i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	return dp[n-1];
}
int main()
{
	int n;
	cin>>n;
	cout<<n;
	cout<<fn(n);
	return 0;
}

