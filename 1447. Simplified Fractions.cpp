#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<string> v;
	
	if(n == 0 || n == 1){
		return 0;
	}
	
	for(int i=2;i<=n;i++){
//		char ch = i + 48;
		stringstream ss;
		ss << i;
		string str = ss.str();
		string x = "1/";
		x = x + str;
		v.push_back(x);
		for(int j = 2;j<i;j++){
			if(__gcd(i,j) == 1){
				string s;
//				char ch1 = j+48,ch2 = i+48;
				stringstream ss1;
				ss1 << j;
				s = ss1.str() +  "/";
				stringstream ss2;
				ss2 << i;
//				str = ss.str();
				s = s + ss2.str();
				v.push_back(s);
			}
		}
//		v.push_back()
	}
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}

