#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int l_max = a[0],r_max=a[n-1],l=0,r=n-1,i=0,ans=0;
	while(l <= r){
		if(l_max <= r_max){
			ans = ans + max(0,l_max - a[l]);
			l_max = max(a[l],l_max);
			l++;
		}
		else{
			ans = ans + max(0,r_max - a[r] );
			r_max = max(a[r],r_max);
			r--;
		}
//		cout<<l_max<<" "<<r_max<<endl;
//		i++;
	}
	cout<<ans;
}

