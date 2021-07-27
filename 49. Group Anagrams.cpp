#include<bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
 string strSort(string s) {
    int counter[26] = {0};
    for (int i = 0;i<s.length();i++) {
        counter[s[i] - 'a']++;
    }
    string t;
    for (int c = 0; c < 26; c++) {
        t += string(counter[c], c + 'a');
    }
    return t;
}
int main(){
	vector<string> v;
	v.push_back("eat");
	v.push_back("tea");
	v.push_back("tan");
	v.push_back("ate");v.push_back("nat");v.push_back("bat");
	
	map<string,vector<string> > m;
	vector<vector<string> > ans;
	for(int i=0;i<v.size();i++){
		string x = strSort(v[i]);
		m[x].push_back(v[i]);
	}
	map<string,vector<string> >::iterator it;
	for(it = m.begin();it!=m.end();++it){
		int i=0;
//		cout<<it->first<<" ->  ";
		vector<string> q;
		while(i < it->second.size()){
			string y = it->second[i];
			q.push_back(y);
//			cout<<it->second[i]<<" ";
			i++;
		}
		ans.push_back(q);
//		cout<<endl;
	}
    for(int i=0;i<ans.size();i++){
      	for(int j=0;j<ans[i].size();j++){
       		cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

