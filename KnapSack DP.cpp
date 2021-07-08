#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int wt[n],cost[n],t;
	
	for(int i=0;i<n;i++)cin>>wt[i];
	for(int j=0;j<n;j++)cin>>cost[j];
	cin>>t;
	
	int a[n+1][t+1];
	
	for(int i=0;i<=t;i++){
		a[0][i] = 0;
	}
	
	for(int i=0;i<=n;i++){
		a[i][0] = 0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t;j++){
			if(wt[i-1] <= j){
				a[i][j] = max(cost[i-1] + a[i-1][j-wt[i-1]],
							a[i-1][j]);
			}
			else a[i][j] = a[i-1][j];
		}
	}
	cout<<a[n][t];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=t;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}


