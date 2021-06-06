#include<bits/stdc++.h>
using namespace std;

string smallestWindow (string s, string p)
    {
        // Your code here
        if(s.length() < p.length()){
            return "-1";
        }
        int m[256]={0},m1[256]={0};
    	for(int i=0;i<p.length();i++)
    	m[p[i]]++;
    	int start=0,start_index=-1;
    	int count=0,min_len = INT_MAX,i=0;
    	for( ;i<s.length();i++){
    		m1[s[i]]++;
    		
    		if(m1[s[i]] <= m[s[i]])
    		count++;
    		if(count == p.length()){
    			while( m1[s[start]] > m[s[start]] 
    			|| m[s[start]] == 0){
    				if(m1[s[start]] > m[s[start]])
    				m1[s[start]]--;
    				start++;
    			}
    			if(min_len > i-start+1){
				min_len = min(min_len,i-start+1);
				start_index = start;
			}
    		}
    	}
        if(start_index == -1){
            return "-1";
        }
    	string ans = s.substr(start_index,min_len);
    	
    	return ans;
    }
    
int main(){
	string s,p="";
	cin>>s>>p;
	cout<<smallestWindow(s,p);
}

