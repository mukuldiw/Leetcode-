#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<string> v;
	v.push_back("a");
	v.push_back("b");
	v.push_back("c");
	int prev = 0;
	vector<char> set;
	set.push_back('a');
	set.push_back('b');
	set.push_back('c');
	
	int now = v.size();
	for(int i=2;i<=n;i++){
		int j = prev;
		while(j < now){
			string s = v[j];
			int x = s.length(),k=0;
			while(k<=2){
				if(set[k] != s[x-1]){
					v.push_back(s+set[k]);
				}
				k++;
			}
			j++;
		}
		for(int l=0;l<v.size();l++){
			cout<<v[l]<<" ";
		}
		cout<<endl;
		prev = now;
		now = v.size();
	}
	string res = "";
        for(int i=0;i<v.size();i++){
            if(v[i].length() == n){
            	if(i+k-1 >= v.size()){
            		break;
				}
                res = v[i+k-1];
                break;
            }
        }
        cout<<endl<<"answer: "<<res;
}

