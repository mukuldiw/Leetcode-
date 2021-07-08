#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	cin>>s>>t;
	int m = s.length(),n = t.length();
	
	int **a = new int*[n+1];
	for(int i=0;i<n+1;i++)a[i] = new int[m+1];
	
	for(int i=0;i<n+1;i++)a[i][0] = 0;
	
	for(int i=0;i<m+1;i++)a[0][i] = 1;
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			
			if(t[i-1] != s[j-1])a[i][j] = a[i][j-1];
			else{
				a[i][j] = a[i-1][j-1] + a[i][j-1];
			}
		}
	}
	cout<<a[n][m];
}

