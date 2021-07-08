#include<bits/stdc++.h>
using namespace std;
void fn(string s,int i,int j,int &ans){
	if(i > j)return;
	if(s[i] == s[j]){
		ans++;
		string x ="";
		for(int t=i;t<=j;t++)
		cout<<s[t];
		cout<<" ";
		fn(s,i+1,j-1,ans);
		return;
//		fn(s,i+1,j-1,ans);
//		
//		fn(s,i+1,j,ans);fn(s,i,j-1,ans);
//		return;
	}
	fn(s,i+1,j,ans);fn(s,i,j-1,ans);
	return;
}
int main(){
	string s;
	cin>>s;
	int ans =0;
	fn(s,0,s.length()-1,ans);
	cout<<ans;
}


