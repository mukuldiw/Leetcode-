#include<bits/stdc++.h>
using namespace std;
void kPartition(int *a,int n,int sum){
	bool **dp = new bool*[n+1];
	for(int i=0;i<n+1;i++){
		dp[i] = new bool[sum+1];
	}
	for(int j=1;j<=sum;j++)dp[0][j] = 0;
	
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
//	cout<<dp[n][sum];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	int n,sum;
	cin>>n>>sum;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	kPartition(a+i,n-i,sum);
}

