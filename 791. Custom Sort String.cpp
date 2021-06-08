#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	cin>>s>>t;
	int a[26]={0};
        for(int i=0;i<s.length();i++){
            a[s[i]-97]++;
        }
        string ans="";
        for(int i=0;i<t.length();i++){
            while(a[t[i]-97]){
                ans = ans + t[i];
                a[t[i]-97]--;
            }
        }
        for(int i=0;i<26;i++){
        	while(a[i]){
        		char ch = i+97;
        		ans = ans + ch;
        		a[i]--;
			}
		}
        cout<<ans;
}

