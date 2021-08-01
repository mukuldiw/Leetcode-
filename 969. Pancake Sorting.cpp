#include<bits/stdc++.h>
using namespace std;

//void reverse(int a[], int n, int k)
//{
//	int i = 0,j = k-1;
//    
//	while(i < j){
//		swap(a[i], a[j]);
//		i++;
//		j--;
//	}
//	return;
//}

int main(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x = n;
	vector<int> v;
	while(x >= 1){
		int ind = 0;
//		cout<<"erge";
		for(int i=0;i<n;i++){
			if(a[i] == x){
				ind = i;
				break;
			}
		}
		if(ind == x - 1){
			x--;
			continue;
		}
		reverse(a,a+ind+1);
		
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		reverse(a,a+x);
		
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
//		cout<<"sdwf";
		v.push_back(ind+1);
		v.push_back(x);
//		break;
		x--;
	}
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}

