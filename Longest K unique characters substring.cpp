#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int k;cin>>k;
	int res = -1;
	int a[26] = {0};
	int l = 0;
	for(int i=0;i<s.length();i++){
		a[s[i]-97]++;
		int count = 0;
		for(int i=0;i<26;i++){
			if(a[i])count++;
		}
		cout<<count<<" "<<l<<endl;
		if(count < k)continue;
		if(count > k){
			while(count > k){
				count = 0;
				a[s[l]-97]--;
				for(int i=0;i<26;i++){
					if(a[i])count++;
				}
				l++;
			}
		}
		if(count == k){
				res = max(res,i - l + 1);
		}
//		cout<<res<<" ";
	}
	cout<<endl<<res;
}

