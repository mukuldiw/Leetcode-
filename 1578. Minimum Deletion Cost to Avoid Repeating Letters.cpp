#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	int n;
	cin>>n;int c[n];for(int i=0;i<n;i++)cin>>c[i];
	
	
    int max_cost = c[0],ans = c[0];
        
    for(int i=1;i<n;i++){
        if(s[i-1] != s[i]){
            ans = ans - max_cost;
            max_cost = 0;
        }
        ans = ans + c[i];
        max_cost = max(max_cost,c[i]);
    }
    cout<<ans-max_cost;
}

