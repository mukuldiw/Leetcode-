#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,f,s;cin>>n>>f>>s;
	int a[n];for(int i=0;i<n;i++)cin>>a[i];
	
	int dp1[n-f+1],dp2[n-s+1];
	for(int i=0;i<n-f;i++)dp1[i]=0;
	for(int i=0;i<n-s;i++)dp2[i]=0;
	
	int sum=0;
	for(int i=0;i<f;i++){
		sum = sum + a[i];
	}
	dp1[0] = sum;
	int k=1,l=0;
	for(int i=f;i<n;i++){
		sum = sum + a[i]-a[l];
		dp1[k] = sum;
		l++;
		k++;
	}
	sum=0;
	for(int i=0;i<s;i++){
		sum = sum + a[i];
	}
	dp2[0] = sum;
	k=1,l=0;
	for(int i=s;i<n;i++){
		sum = sum + a[i]-a[l];
		dp2[k] = sum;
		l++;
		k++;
	}
	cout<<endl;
	for(int i=0;i<n-f+1;i++){
		cout<<dp1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n-s+1;i++){
		cout<<dp2[i]<<" ";
	}
	cout<<endl<<endl;
	int res=0;
	for(int i=0;i<n-f+1;i++){
		int x = dp1[i];
		int j = i + f,m=0;
		if(j < n-s+1){
			while(j< n-s+1){
				m = max(m,x+dp2[j]);
				j++;
			}
		}
		j = i-s; 
//		int m1=0;
		if(j >= 0){
//			cout<<dp2[j]<<" ";
			while(j>=0){
				m = max(m,dp2[j]+x);
				j--;
			}
//			cout<<m<<" ";
		}
		cout<<m<<" ";
		res = max(res,m);
	}
	cout<<endl;
	cout<<res;

}

