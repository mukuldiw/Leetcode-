#include<bits/stdc++.h>
using namespace std;
int fn(int **a,int **dp,int m,int n,int i,int j){
	
	if((i<0 || j<0 || i>m-1 || j>n-1))return 0;
	
	if(dp[i][j]!=0 )return dp[i][j];
	
	int x=-1,y=-1,z=-1;
	if (i%2 != 0 && j < n - 1 && ((a[i][j + 1] != -1)))
        x = 1 + fn(a, dp,m,n,i,j+1);

    if (i%2 == 0 && j > 0 && a[i][j - 1] != -1)
        x = 1 + fn(a, dp,m,n,i,j-1);
        
    if (i < m - 1 && (a[i + 1][j] != -1))
        y = 1 + fn(a, dp,m,n,i+1,j);
        
	return dp[i][j] = max(x,y);
}
int main(){
	int m,n;cin>>m>>n;
	
	int **a = new int*[m];
	for(int i=0;i<m;i++)a[i]=new int[n];
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	int **dp = new int*[m];
	for(int i=0;i<m;i++)dp[i]=new int[n];
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=-1 && dp[i][j] == 0){
				fn(a,dp,m,n,i,j);
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
//5 5
//1 1 -1 1 1
//1 0 0 -1 1
//1 1 1 1 -1
//-1 -1 1 1 1
//1 1 -1 -1 1

