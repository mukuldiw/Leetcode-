#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	string s = "";
	cin>>n>>t;
	while(n--){
		int x = t-n;
		char ch = 96+x;
		if(x > 26){
			ch = 122;
			s = s + ch;
			t = t - 26;
		}
		else {
			s = s + ch;
			t = t - x;
		}
	}
	cout<<s;
}

