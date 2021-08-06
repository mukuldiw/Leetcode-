#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int a[26]={0},b[26]={0};
	for(int i=1;i<s.length();i++)b[s[i]-97]++;
	a[s[0]-97] = 1;
	
	int count = 0;
	for(int j=1;j<s.length();j++){
		int flag = 1,count1 = 0, count2 = 0;
		for(int i=0;i<26;i++){
			if(a[i])count1++;
		}
		for(int i=0;i<26;i++){
			if(b[i])count2++;
		}
		if(count1 != count2)flag = 0;
		
		if(flag == 1)count++;
		
		a[s[j]-97]++;b[s[j]-97]--;
	}
	cout<<count;
}

