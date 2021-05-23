#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int i=0,j=n-1;
	int sum1=0,sum2=0,x=0,f=0;
	while(x<n){
		if(a[i] >= a[j]){
			if(f==0){
				sum1 = sum1 + a[i];
				f=1;
			}
			else{
				sum2 = sum2 + a[i];
				f=0;
			}
			i++;
		}
		else{
			if(f==0){
				sum1 = sum1 + a[j];
				f=1;
			}
			else{
				sum2 = sum2 + a[j];
				f=0;
			}
			j--;
		}
		cout<<sum1<<" "<<sum2<<endl;
		x++;
	}
	
}


