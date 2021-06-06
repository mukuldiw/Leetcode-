#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	deque<int> q(k);
	vector<int> v;
//	q.insertLast();
	for(int i=0;i<k;i++){
		while(q.size() && a[i] >= a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		cout<<q.front()<<" ";
	}

//	for(int i=0;i<k;i++)
	v.push_back(a[q.front()]);
	
	for(int i=k;i<n;i++){
		while(i - q.front() >= k && q.size()){
			q.pop_front();
		}
		while(q.size() && a[i] >= a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		v.push_back(a[q.front()]);
		cout<<q.front()<<" ";
		
	}
	cout<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}

