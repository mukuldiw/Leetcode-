#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,x;cin>>s>>x;
	int flag = 1;
	while(flag){
		int n = s.length(),m = x.length();
		int flag = 1,ind;
//	    string res = "";
	    for(int i=0;i<n;i++){
	        if(s[i] == x[0]){
	        	flag = 0;
				ind = i;
				break;	
			}
		}
		map<pair<int,int>,int> m1;
//		if(flag == 0)break;
		if(ind + m < s.length() && n-m >= 0)
		s = s.substr(0,ind) + s.substr(ind+m,n-m);
		cout<<s<<endl;
	}
//	cout<<res;

}

