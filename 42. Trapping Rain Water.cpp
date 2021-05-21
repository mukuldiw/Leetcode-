#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	int l_max = 0,r_max = 0,l=0,r=n-1;
//	int *dp = new int[n];
//	for(int i=0;i<n;i++)
//	dp[i] = 0;
	int ans= 0;
	while(l <= r){
		if(l_max <= r_max){
			ans = ans + max(0,a[l]-l_max);
			l_max = max(l_max,a[l]);
			l++;
		}
		else{
			ans = ans + max(0,a[r]-r_max);
			r_max = max(r_max,a[r]);
			r--;
		}
	}
	cout<<ans;
}

