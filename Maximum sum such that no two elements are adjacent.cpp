#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;int a[n];for(int i=0;i<n;i++)cin>>a[i];

	int dp1[n];
	dp1[0] = a[0];
	dp1[1] = a[1];
	int m2 = dp1[0],ans=max(a[0],a[1]);
	
	for(int i=2;i<n;i++){
		dp1[i] = a[i] + m2;
		m2 = max(m2,dp1[i-1]);
		ans = max(ans,dp1[i]);
	}
	cout<<ans;
	
}

