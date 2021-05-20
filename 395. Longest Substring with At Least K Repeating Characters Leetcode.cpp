#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	map<char,int> m;
	int n = s.length(),ans=0,x=0;
	for(int i=0;i<n;i++){
		m[s[i]]++;
		int flag=0;
		map<char,int>::iterator it;
		for(it = m.begin();it!=m.end();++it){
			if(it->second < k){
				flag=1;
				break;
			}
		}
		if(flag== 0)
		ans = i-x+1;
	}
	cout<<ans;
}

