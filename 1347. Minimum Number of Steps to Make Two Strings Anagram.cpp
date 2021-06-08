#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	cin>>s>>t;
	int n = s.length(),a[26]={0},b[26]={0};
	for(int i=0;i<n;i++){
		a[s[i]-97]++;
		b[t[i]-97]++;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		if(b[s[i]-97] < a[s[i]-97]){
			ans = ans + a[s[i]-97] - b[s[i]-97] ;
			a[s[i]-97] = 0;
		}
	}
	cout<<ans;
}

