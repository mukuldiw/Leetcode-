#include<bits/stdc++.h>
#include<string>
using namespace std;
bool comp(string x,string y){
	string X = x+y;
	string Y = y+x;
	return X.compare(Y) > 0 ? 1 : 0;
}
int main(){
	string str;
	int num = 44;
	stringstream ss;  
	  ss << num;  
	  ss >> str; 
//	auto s = std::to_string(42);
	vector<string> s;
	s.push_back("3");
	s.push_back("30");
	s.push_back("34");
	s.push_back("5");
	s.push_back("9");
	sort(s.begin(),s.end(),comp);
	for(int i=0;i<s.size();i++)
	cout<<s[i]<<" ";
}

