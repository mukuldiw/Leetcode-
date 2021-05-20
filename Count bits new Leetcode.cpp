#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> dp;
//	for(int i=0;i<n;i++)
//	dp[i]=0;
	dp.push_back(0);
	dp.push_back(1);
	dp.push_back(1);
	dp.push_back(2);
//	cout<<dp[2];
	int  count=1;
	for(int i=4;i<=n;i++){
		dp.push_back(1);
		int x=2,l=1;
		while(1){
			if(count + l == 0)
			break;
			int y=0;
			while(y < count+l){
				dp.push_back(x);
				i++;
				if(i >= n){
					count=-1;
					l=2;
					break;
				}
//				j++;
				y++;
			}
			l--;
			x++;
		}
		count++;
//		i=j-1;
	}
	vector<int> v;
	int sum=0;
	for(int i=0;i<=n;i++)
//	sum+=dp[i];
	cout<<dp[i]<<" ";
}
