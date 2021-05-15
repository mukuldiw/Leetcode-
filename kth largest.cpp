#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	int a[n],count=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] == 1)
		count++;
	}
	while(q){
		int x,y;
		cin>>x>>y;
		if(x == 1){
			if(y <= count)
			count--;
			else
			count++;
		}
		if(x == 2){
			if(y<=count)
			cout<<"1"<<endl;
			else
			cout<<"0"<<endl;
		}
		q--;
	}
}

