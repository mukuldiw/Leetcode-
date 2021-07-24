#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	if(n == 1){
		cout<<a[0];
		return 0;
	}
	int x = a[0] xor a[1];
	int y = a[n-2] xor a[n-1];
	
	if(x != 0){
		cout<<a[0];
		return 0;
	}
	if(y != 0){
		cout<<a[n-1];
		return 0;
	}
	int l = 0,r = n-1,mid;
	while(l <= r){
		mid = l + (r-l)/2;
		cout<<l<<" "<<mid<<" "<<r<<endl;
		x = a[mid] xor a[mid+1];
		y = a[mid] xor a[mid-1];
		
		if(x != 0 && y!= 0){
			cout<<a[mid];
			return 0;
		}
		if((mid)%2 == 0){
			
			if(x== 0){
				l = mid + 1;
//				cout<<x;
			}
			else{
				r = mid-1;
			}
			
		}
		else{
			x = a[mid] xor a[mid-1];
			if(x == 0){
				l = mid+1;
			}
			else{
				r = mid-1;
			}
//			cout<<l<<" "<<mid<<" "<<r<<endl;
		}
	}
}

