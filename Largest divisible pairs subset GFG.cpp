#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;int a[n];for(int i=0;i<n;i++)cin>>a[i];
	int dp[n] = {0};
	dp[n-1] = 1;
	sort(a,a+n);
	for(int i=n-2;i>=0;i--){
		int m = 0;
		for(int j = i+1; j < n;j++){
			if(a[j]%a[i] == 0){
				m = max(m,dp[j]);
			}
		}
		dp[i] = 1 + m;
	}
	cout<<*max_element(dp,dp+n);
}


