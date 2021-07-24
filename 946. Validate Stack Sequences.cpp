#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int a[n],b[n];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	
	stack<int> s;
	int j=0;
	bool flag = true;
	
	for(int i=0;i<n;i++){
		if(a[i] != b[j] && b[j] != s.top()){
		s.push(a[i]);
//		i++;
		}
		else if(b[j] == a[i]){
			j++;
//			i++;
		}
//		else if(b[j] == s.top()) {
//			s.pop();
//			j++;
//			s.push(a[i]);
//			i++;
//		}
		cout<<s.top()<<endl;
	}
//	while(j < n){
//		if(b[j] != s[s.size()-1] ){
//			flag = false;
//		}
//		j++;
//		s.pop_back();
//	}
	if(s.size())flag = false;
	cout<<flag;
}

