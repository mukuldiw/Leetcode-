#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,l,r;
	cin>>n>>l>>r;
	vector<int> v;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	vector<int> ans;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + v[i];
            ans.push_back(sum);
        }
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
        int j = 1;
        for(int i=0;i<n;i++){
            int x = ans.size();
            while(j < x){
                ans.push_back(ans[j] - v[i]);
                j++;
            }
            for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
            j = x+1;
        }
        
        
        
}

