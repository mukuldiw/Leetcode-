#include<bits/stdc++.h>
using namespace std;
string val(string s){
	string x= "";
	int d[26]={0};
//	for(int i=0;i<26;i++)
//	d[i]=1;
	for(int i=0;i<s.length();i++){
		int count=1;
		if(s[i] == s[i+1]){
//			count=0;
			while(s[i] == s[i+1] && i<s.length()){
//				d[s[i]-97]++;
				count++;
				i++;
			}
		
		}
		else{
				d[s[i]-97]++;
				count = d[s[i]-97];
		}
	//			i++;
	//		}
			ostringstream convert;   
	        convert << count;
	        x = x + convert.str();
		}
	return x;
	
}

int main(){
	string s;
	cin>>s;
	string x = val(s);
	cout<<s<<" "<<x<<endl;
	vector<string> v;
	vector<string> ans;
	v.push_back("ktittgzawn");
	v.push_back("dgphvfjniv");
	v.push_back("gceqobzmis");
	v.push_back("alrztxdlah");
	v.push_back("jijuevoioe");
	v.push_back("mawiizpkub");
	v.push_back("onwpmnujos");
	v.push_back("zszkptjgzj");
	v.push_back("zwfvzhrucv");
	v.push_back("isyaphcszn");
//	v.push_back("zdqmjnczma");
//	v.push_back("ccc");
	for(int i=0;i<v.size();i++){
		string y = val(v[i]);
		cout<<v[i]<<" "<<y<<endl;
		int t = x.compare(y);
		if(t == 0){
			ans.push_back(v[i]);
		}
	}
//	for(int i=0;i<ans.size();i++){
//		cout<<ans[i]<<" ";
//	}
}

