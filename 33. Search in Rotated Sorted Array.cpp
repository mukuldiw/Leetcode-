#include<bits/stdc++.h>
using namespace std;
//int bin(int *a,int k,int l,int )
int search(int* a, int k,int n) {
//            int n=a.size();    
            int l=0,r=n-1;
        
            while(l<=r){
                int mid = (l+r)/2;
                if(a[mid] == k){
                    return mid;
                    // break;
                }
                if(a[l] <= a[mid]){
                    if(a[mid] > k && k >= a[l])
                        r=mid-1;
                    else
                        l=mid+1;
                }
                if(a[mid] < a[l]){
                    if(a[mid] < k && a[r] <= k)
                        l = mid+1;
                    else
                        r=mid-1;
                }         
            }
        return -1;
    }
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<search(a,k,n);
}
