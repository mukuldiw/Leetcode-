#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	bool **dp = new bool*[n+1];
	for(int i=0;i<n+1;i++){
		dp[i] = new bool[sum+1];
	}
	for(int j=1;j<=sum;j++)dp[0][j] = 0;
//	for(int i=0;i<n+1;i++)dp[i][0] = 1;
	
	for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
 
        for (int j = 1; i > 0 && j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (a[i - 1] <= j) {
                dp[i][j] |= dp[i - 1][j - a[i - 1]];
            }
        }
    }
	
	int ind;
	for( int i=1;i<=sum/2;i++){
		if(dp[n][i]){
			ind = i;
		}
	}
	int ans = sum-2*ind;
	
	cout<<"Min Diff: "<<ans;

}

