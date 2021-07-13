#include<bits/stdc++.h>
using namespace std;
void adjacent(int **a,int **dp,int m,int n,int &count,int i,int j){
	if(dp[i][j] == 1)return;
	
	dp[i][j] = 1;
	
	if(a[i][j+1] == a[i][j] + 1 && i<m && j<n-1){
		count++;
		adjacent(a,dp,m,n,count,i,j+1);
	}
	if(a[i][j-1] == a[i][j] + 1 && i<m && j>0){
		count++;
		adjacent(a,dp,m,n,count,i,j-1);
	}
	if(a[i-1][j] == a[i][j] + 1 && i>0 &&j <n){
		count++;
		adjacent(a,dp,m,n,count,i-1,j+1);
	}
	if(a[i+1][j] == a[i][j] + 1 && i<m-1 && j<n){
		count++;
		adjacent(a,dp,m,n,count,i+1,j);
	}
}

int main(){
	int m,n;
	cin>>m>>n;
	
	int **a = new int*[m];
	for(int i=0;i<m;i++)a[i] = new int[n];
	
	int **dp = new int*[m];
	for(int i=0;i<m;i++)dp[i] = new int[n];
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = 0;
		}
	}
	int ans = 0,count;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(dp[i][j] == 0){
				count = 0;
				adjacent(a,dp,m,n,count,i,j);
				ans = max(ans,count);
			}
		}
	}
	cout<<ans;
}
	
