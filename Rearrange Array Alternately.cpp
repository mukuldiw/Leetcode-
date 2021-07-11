#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;int a[n];for(int i=0;i<n;i++)cin>>a[i];
	
	int min_ind = a[0],max_ind = a[n-1],l=0,r=n-1,i=0;
	
	while(l < r){
		if(i%2 == 0){
//			int x = 
			a[i] = max_ind;
			r--;
			max_ind = a[r];
		}
		else{
			int x = a[l+1];
			a[i] = min_ind;
			l++;
			min_ind = x;
		}
		i++;
	}
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
	
