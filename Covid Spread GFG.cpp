#include<bits/stdc++.h>
using namespace std;
//int fn(int **a,int n,int m){
//	
//        int count=0;
//    	for(int i=0;i<n;i++){
//    		for(int j=0;j<m;j++){
//    			int neigh=0;
//    			if(a[i][j] == 1){
//    				if(a[i][j+1] == 0 && j<m-1)
//    				neigh++;
//    				if(a[i][j-1] == 0 && j>0)
//    				neigh++;
//    				if(a[i+1][j] == 0 && i<n-1)
//    				neigh++;
//    				if(a[i-1][j] == 0 && i>0)
//    				neigh++;
//    			}
//    			if((i == 0 && j==0) || (i==0 && j==m-1) || (i==n-1 && j==0) || (i == n-1 && j==m-1)){
//    				if(neigh == 2){
//    					return -1;
//    				}
//    			}
//    			else if(i == 0 || i == n-1){
//    					if((j!=0) && (j!=m-1) ){
//    						if(neigh == 3)
//    						{
//    							return -1;
//    						}
//    				}
//    			}
//    			else if((i > 0 && i < n-1) && (j > 0 && j < m-1)){
//    				if(neigh == 4)
//    				return -1;
//    			}
//    		}
//    	}
//    	
//    	int **dp = new int*[n];
//    	for(int i=0;i<n;i++)
//    	dp[i] = new int[m];
//    	
//    	for(int i=0;i<n;i++){
//    		for(int j=0;j<m;j++){
//    			dp[i][j] = 0;
//    		}
//    	}
//    	
//    	int ones = 1;
//    	while(ones){
//    		ones=0;
//    		for(int i=0;i<n;i++){
//    			for(int j=0;j<m;j++){
//    				if(a[i][j] == 2 ){
//    					dp[i][j] = 2;
//    					if(a[i][j+1] == 1 && j < m-1)
//    					dp[i][j+1] = 2;
//    					if(a[i][j-1] == 1 && j > 0)
//    					dp[i][j-1] = 2;
//    					if(a[i-1][j] == 1 && i > 0)
//    					dp[i-1][j] = 2;
//    					if(a[i+1][j] == 1 && i < n-1)
//    					dp[i+1][j] = 2;
//    					
//    				}
//    			}
//    		}
//    		
//    		for(int i=0;i<n;i++){
//    			for(int j=0;j<m;j++){
//    				if(dp[i][j] == 2)
//    				a[i][j] = 2;
//    			}
//    		}
//    		for(int i=0;i<n;i++){
//    			for(int j=0;j<m;j++){
//    				if(a[i][j] == 1){
//    					ones++;
//    				}
//    			}
//    		}
//
//    		count++;
//    	}
//    	return count;
//}

int main(){
	int n,m;
	cin>>n>>m;
	int **a = new int*[n];
	for(int i=0;i<n;i++){
		a[i] = new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
//	cout<<fn(a,n,m);
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int neigh=0;
			if(a[i][j] == 1){
				if(a[i][j+1] == 0 && j<m-1)
				neigh++;
				if(a[i][j-1] == 0 && j>0)
				neigh++;
				if(a[i+1][j] == 0 && i<n-1)
				neigh++;
				if(a[i-1][j] == 0 && i>0)
				neigh++;
			}
			if((i == 0 && j==0) || (i==0 && j==m-1) || (i==n-1 && j==0) || (i == n-1 && j==m-1)){
				if(neigh == 2){
					count = -1;
				}
			}
			else if(i == 0 || i == n-1){
					if((j!=0) || (j!=m-1) ){
						if(neigh == 3)
						{
							count == -1;
						}
				}
			}
			else if((i > 0 && i < n-1) && (j > 0 && j < m-1)){
				if(neigh == 4)
				count = -1;
			}
		}
	}
	if(count == -1){
		cout<<"count: "<<count;
		return 0;
	}
	
	int **dp = new int*[n];
	for(int i=0;i<n;i++)
	dp[i] = new int[m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j] = 0;
		}
	}
	
	int ones = 1;
	while(ones){
		ones=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j] == 2 ){
					dp[i][j] = 2;
					if(a[i][j+1] == 1 && j < m-1)
					dp[i][j+1] = 2;
					if(a[i][j-1] == 1 && j > 0)
					dp[i][j-1] = 2;
					if(a[i-1][j] == 1 && i > 0)
					dp[i-1][j] = 2;
					if(a[i+1][j] == 1 && i < n-1)
					dp[i+1][j] = 2;
					
				}
			}
		}
		
//		cout<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(dp[i][j] == 2)
				a[i][j] = 2;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j] == 1){
					ones++;
				}
			}
		}
//		for(int i=0;i<n;i++){
//			for(int j=0;j<m;j++){
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		count++;
	}
	
	cout<<count;
}

