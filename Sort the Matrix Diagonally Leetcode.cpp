#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int x = n-1,y = m-1,count=1;
	while(x >=0){
		int j=x,b[count];
		for(int i = 0;i<count;i++){
			b[i] = a[j][i];
			j++;
		}
		j=x;
		sort(b,b+count);
		for(int i = 0;i<count;i++){
			a[j][i] = b[i];
			j++;
		}
//		cout<<endl;
		count++;
		x--;
	}
	x = 0,y = 1,count=n;
	while(y < m){
		int b[count];
		int i=0,j=y;
		while(j < m){
			b[i] = a[i][j];
			i++;
			j++;
		}
		sort(b,b+count);
		i=0,j=y;
		while(j < m){
			a[i][j]= b[i];
			i++;
			j++;
		}
;
		count--;
		y++;
	}
	cout<<endl;
	vector< vector<int> > v;
	
	for(int i=0;i<n;i++){
		vector<int> v1;
		for(int j=0;j<m;j++){
			v1.push_back(a[i][j]);
		}
		v.push_back(v1);
//		cout<<endl;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
//11 25 66 1 69 7
//23 55 17 45 15 52
//75 31 36 44 58 8
//22 27 33 25 68 4
//84 28 14 11 5 50

