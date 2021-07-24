#include<bits/stdc++.h>
using namespace std;

void dfs(char **a,int **dp,int m,int n,int i,int j){
	if(dp[i][j] == 1 || i<0 || j<0 || i>=m || j>=n)return;
	if(dp[i][j] == 0)dp[i][j]=1;
	
	if(a[i+1][j] == 'X' && i<m-1){
		dfs(a,dp,m,n,i+1,j);
		return;
	}
	if(a[i][j+1] == 'X' && j< n-1){
		dfs(a,dp,m,n,i,j+1);
		return;
	}
}
int main(){
	int n,m;cin>>m>>n;
	char **a = new char*[m];
        for(int i=0;i<m;i++)a[i] = new char[n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            	cin>>a[i][j];
            }
        }
	int **dp = new int*[m];
        for(int i=0;i<m;i++)dp[i] = new int[n];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = 0;
            }
        }
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j] == 'X' && dp[i][j] == 0){
                    count++;
                     dfs(a,dp,m,n,i,j);
                }
            }
        }
        cout<<count;
}

