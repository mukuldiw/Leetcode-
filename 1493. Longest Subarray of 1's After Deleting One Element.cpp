#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int dp[n] = {0},sum=0;
	for(int i=n-1;i>=0;i--){
		sum = sum + a[i];
		dp[i] = sum;
		
		if(a[i] == 0 ){
			sum = 0;
		}
	}
	int z = 0, l = n, res = 0;
	
	for(int i=n-1;i>=0;i--){
		if(a[i] == 0){
			l = i;
			break;
		}
	}
	
	if(l == n){
		cout<<n;
		return 0;
	}
	sum  = 0;
	for(int i=n-1;i>=0;i--){
		
		if( a[i] == 0 ){
			z++;
		}
		if(z == 2 && a[i] == 0){
			z--;
			sum = sum - dp[l];
			l = i;
		}
		else   sum += 1;
		
		res = max(res,sum);
	}
	
	cout<<res;
	
//	for(int i=0;i<n;i++){
//		cout<<dp[i]<<" ";
//	}
}

