#include<bits/stdc++.h>
using namespace std;
void display(const vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
}
void getSubsets(int *arr,int** dp, int i,int sum,vector<int> &p){
	if (i == 0 && sum != 0 && dp[0][sum])
    {
        p.push_back(arr[i]);
        // Display Only when Sum of elements of p is equal to sum
          if (arr[i] == sum)
              display(p);
        return;
    }
 
    // If sum becomes 0
    if (i == 0 && sum == 0)
    {
        display(p);
        return;
    }
 
    // If given sum can be achieved after ignoring
    // current element.
    if (dp[i-1][sum])
    {
        // Create a new vector to store path
        vector<int> b = p;
        getSubsets(arr, dp, i-1, sum, b);
    }
 
    // If given sum can be achieved after considering
    // current element.
    if (sum >= arr[i] && dp[i-1][sum-arr[i]])
    {
        p.push_back(arr[i]);
        getSubsets(arr, dp, i-1, sum-arr[i], p);
    }
}
int main(){
	int n,sum;
	cin>>n>>sum;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int **dp = new int*[n];
	for(int i=0;i<n;i++){
		dp[i] = new int[sum+1];
		dp[i][0] = true;
	}
	if (a[0] <= sum)
       dp[0][a[0]] = 1;
    
	for (int i = 1; i < n; ++i)
        for (int j = 0; j < sum + 1; ++j)
            dp[i][j] = (a[i] <= j) ? dp[i-1][j] ||
                                       dp[i-1][j-a[i]]
                                     : dp[i - 1][j];
//	cout<<dp[n-1][sum]<<endl;
	vector<int> v;
	getSubsets(a,dp,n-1,sum,v);
}

