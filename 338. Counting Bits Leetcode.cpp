#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int dp[n];
	for(int i=0;i<n;i++)
	dp[i]=0;
	dp[0]=0;
	dp[1]=1;
//	if(n==0)
////	cout<<dp[0];
//	else if(n == 1){
////		cout<<dp[1];
//	}
//	else{
		for(int i=2;i<n;i++){
//			cout<<i;
			int j=i,x=1,l=1;
			dp[j] = x;
			x++;
			j++;
			while(x <= i && j< n){
				for(int k=0;k<(i-l);k++){
					dp[j] = x;
					j++;
					
				}
				x++;
				l++;
			}
			i=j-1;
//			cout<<i<<endl;
			
		}
//	}
	for(int i=0;i<n;i++)
	cout<<dp[i]<<" ";
}

