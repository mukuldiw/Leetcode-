#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	int i=0,p_diff=INT_MAX,ans;
	while(i < n-2){
		int l=i+1,r=n-1;
		while(l<r){
			int sum = a[i] + a[l] + a[r];
			int diff = abs(x-sum);
			if(diff == 0){
				ans = sum;
				break;
			}
			else if(sum > x)
			r--;
			else
			l++;
			if(diff < p_diff){
				p_diff = diff;
				ans = sum;
			}
			cout<<sum<<" ";
		}
		i++;
	}
	cout<<endl<<ans;
}
