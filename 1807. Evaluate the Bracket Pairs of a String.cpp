#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	vector<vector<string> > v;
	vector<string> v1;
	v1.push_back("name");
	v1.push_back("bob");
	v.push_back(v1);
	v1.pop_back();
	v1.pop_back();
	v1.push_back("age");
	v1.push_back("two");
	v.push_back(v1);
	map<string,string> m;
	map<string,int> m1;
	m["name"] = "bob";
	m["age"] = "two";
	m1["name"]=1;
	m1["age"]=1;
	string ans="";
	for(int i=0;i<s.length();i++){
		string x="";
		if(s[i] == '(' ){
            int j=i;
            while(s[i] != ')'){
                i++;
            }
            x = s.substr(j+1,i-j-1);
            cout<<x<<" ";
            if(m1[x])
            ans = ans + m[x];
            else ans = ans + "?";
        }
        else{
        	ans = ans + s[i];
		}
	}
	cout<<endl<<ans;
}

