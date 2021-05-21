#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n][2];
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	int wait = a[0][1],tot = a[0][0] + wait;
//	cout<<tot<<" "<<wait<<endl;
	for(int i=1;i<n;i++){
		if(a[i][0] > tot){
			tot = a[i][0] + a[i][1];
			wait = wait + a[i][1];
		}
		else{
			tot = tot + a[i][1];
			wait = wait + tot - a[i][0];
		}
//		cout<<tot<<" "<<wait<<endl;
	}
	double ans = double(wait)/double(n);
	cout << setprecision(5) << ans;
}

