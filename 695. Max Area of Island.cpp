#include<bits/stdc++.h>
using namespace std;
void fn(int **a,int **dp,int m,int n,int &count,int i,int j){
	if( i< 0 || j<0 || i==m || j == n)
	return;
	if(a[i][j] == 1 && dp[i][j] == 0){
		dp[i][j] = 1;
		count++;
		
		fn(a,dp,m,n,count,i+1,j);
		fn(a,dp,m,n,count,i,j+1);
		fn(a,dp,m,n,count,i-1,j);
		fn(a,dp,m,n,count,i,j-1);
	}
}
int main(){
	int m,n;
	cin>>m>>n;
	int **a = new int*[m];
	for(int i=0;i<m;i++)
	a[i] = new int[n];
	
//	0 0 1 0 0 0 0 1 0 0 0 0 0
//	0 0 0 0 0 0 0 1 1 1 0 0 0
//	0 1 1 0 1 0 0 0 0 0 0 0 0
//	0 1 0 0 1 1 0 0 1 0 1 0 0
//	0 1 0 0 1 1 0 0 1 1 1 0 0
//	0 0 0 0 0 0 0 0 0 0 1 0 0
//	0 0 0 0 0 0 0 1 1 1 0 0 0
//	0 0 0 0 0 0 0 1 1 0 0 0 0
			
	int **dp = new int*[m];
	for(int i=0;i<m;i++)
	dp[i] = new int[n];
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dp[i][j]=0;
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int ans = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j] == 1 && dp[i][j] == 0){
				int count = 0;
				fn(a,dp,m,n,count,i,j);
				ans = max(ans,count);
//				cout<<count<<" ";
			}
		}
	}
	cout<<ans;
}

