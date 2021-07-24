#include<bits/stdc++.h>
using namespace std;

void reverseStr(string& str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

int main(){
	string s;
	cin>>s;
	stack<int> st;
	for(int i=0;i<s.length();i++){
		if(s[i] == '('){
			st.push(i);
			continue;
		}
		if(s[i] == ')'){
			string x = s.substr(st.top()+1,i-st.top()-1);
			reverseStr(x);
			s = s.substr(0,st.top()) + x + s.substr(i+1,s.length()-i+1);
			st.pop();
			i = i-3;
			cout<<s<<endl;
		}
	}
}

