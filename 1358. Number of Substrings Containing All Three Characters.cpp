#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.length();
	int a[3] = {1,1,1};
	vector<int> v;
	for(int i=0;i<n;i++){
		string x = s.substr(i,3);
		int flag = 0;
		if((x[0] == 'a' || x[1] == 'a' || x[2] == 'a')
		&&(x[0] == 'b' || x[1] == 'b' || x[2] == 'b')
		&&(x[0] == 'c' || x[1] == 'c' ||x[2] == 'c' )){
			flag = 1;
		}
		if(flag == 1){
			v.push_back(i);
		}
	}
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
	int res = 0;
	for(int i=0;i<v.size();i++){
		int x = v[i];
		res = res + ((n)-(x+2));
//		cout<<res<<" ";
	}
	cout<<endl<<res;
}

