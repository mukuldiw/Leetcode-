#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int i=0,j=0;
	while(i < n){
		int x = i,y=j;
		while(x<n){
			int t = a[i][y];
			a[i][y] = a[x][j];
			a[x][j] = t;
			x++;
			y++;
		}
		i++;
		j++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int h=0;h<n;h++){
		int x = n-1-h;
		if(x >= n/2){
			for(int k=0;k<n;k++){
				
				int t = a[h][k];
				a[h][k] = a[x][k];
				a[x][k] = t;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

