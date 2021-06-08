#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.length();
	map<char,int> m,m1;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		m[s[i]]=1;
		a[i] = m.size();
	}
	for(int i=n-1;i>=0;i--){
		m1[s[i]]=1;
		b[i] = m1.size();
	}
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<n;i++){
//		cout<<b[i]<<" ";
//	}
	int count=0;
	for(int i=n-1;i>0;i--){
		if(b[i] == a[i-1])
		count++;
	}
	cout<<endl<<count;
}

