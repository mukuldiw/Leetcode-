#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	vector< vector<int> > v;
	vector<int> x;
	v.push_back(x);
	x.push_back(a[0]);   
	v.push_back(x);
	for(int i=1;i<n;i++){
		int j=v.size(),k=0;
		vector<int> y;
		while(j-- ){
			if(k==0){
				k++;
				continue;
			}
			vector<int> y;
			y = v[k];
			y.push_back(a[i]);
			v.push_back(y);
			k++;
		}
		y.push_back(a[i]);
		v.push_back(y);
	}
	cout<<v.size();
//	for (int i = 0; i < v.size(); i++) {
//        for (int j = 0; j < v[i].size(); j++)
//            cout << v[i][j] << " ";
//        cout << endl;
//    }
}

