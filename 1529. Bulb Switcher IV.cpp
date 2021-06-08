#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length(),count=0;
	for(int i=n-1;i>0;i--){
		if(s[i] != s[i-1]){
			count++;
		}
	}
	if(s[0] == '1' )
	count++;
	cout<<count;
}

