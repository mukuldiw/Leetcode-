#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int a[n][m];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>a[i][j];
	int x = a[0][0],i=0,j=n-1,flag=0;
	while(1 && i<m && j>=0){
		if(a[i][j] == k){
			flag=1;
			break;
		}
		if(a[i][j] > x){
			i++;
			j--;
		}
	}
	cout<<flag;
}
//5 5 31
//1 4 7 11 15
//2 5 8 12 19
//3 6 9 16 22
//10 13 14 17 24
//18 21 23 26 30

