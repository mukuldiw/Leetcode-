#include<bits/stdc++.h>
using namespace std;

void recRemove(string s,int i,string &ans,int n){
	if(i >= n)return;

	if(s[i] == s[i+1]){
		if(s[i] != s[i+2] && i+2 < n){
			recRemove(s,i+2,ans,n);
		}
		else recRemove(s,i+1,ans,n);
	}
	if(s[i] != s[i+1] && i<n-1){
		ans = ans + s[i];
		recRemove(s,i+1,ans,n);
	}
}
int main(){
	string s;
	cin>>s;
	string ans = "";
	recRemove(s,0,ans,s.length());
	if(s[s.length()-2] != s[s.length()-1])ans = ans + s[s.length()-1];
	cout<<ans;
}

