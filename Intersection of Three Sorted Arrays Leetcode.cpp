#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	int a[x],b[y],c[z];
	for(int i=0;i<x;i++)
	cin>>a[i];
	for(int i=0;i<y;i++)
	cin>>b[i];
	for(int i=0;i<z;i++)
	cin>>c[i];
	
	int i=0,j=0,k=0;
	vector<int> v;
	while(i < x && j < y && k < z){
		if(a[i] == b[j] && a[i] == c[k]){
			v.push_back(a[i]);
			i++;
			j++;
			k++;
			continue;
		}
		if( (a[i] > b[j] && a[i] > c[k]) ){
			j++;
			k++;
		}
		else if( (a[i] > b[j] && a[i] >= c[k]) ){
			j++;
//			k++;
		}
		else if( (a[i] >= b[j] && a[i] > c[k]) ){
//			j++;
			k++;
		}
		
		else if( (b[j] > a[i] && b[j] > c[k] ) ){
			k++;
			i++;
		}
		else if( ( b[j] >= a[i] && b[j] > c[k] ) ){
			k++;
//			i++;
		}
		else if( ( b[j] > a[i] && b[j] >= c[k] ) ){
//			k++;
			i++;
		}
		else if( (c[k] > b[j] && c[k] > a[i]) ){
			i++;
			j++;
		}
		else if( (c[k] >= b[j] && a[i] < c[k]) ){
			i++;
//			j++;
		}
		else if( (c[k] > b[j] && c[k] >= a[i]) ){
//			i++;
			j++;
		}
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}

