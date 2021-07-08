#include<bits/stdc++.h>
using namespace std;
bool fn(int *a, int n, int *visited, int i){
	if(i<0 || i>n-1 || visited[i])return false;
	
	if(a[i] == 0)return true;
	
	visited[i] = 1;
	return fn(a,n,visited,i + a[i]) ||	fn(a,n,visited,i - a[i]);
}
int main(){
	int n,st;
	cin>>n>>st;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int *visited = new int[n];
	for(int i=0;i<n;i++)visited[i] = 0;
	
	cout<<fn(a,n,visited,st);
}
