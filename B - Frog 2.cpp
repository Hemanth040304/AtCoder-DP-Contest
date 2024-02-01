//https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr, int i, int n, int k, vector<int>&dp){
    if(i>n)return 0;
    if(i==n-1)return 0;
    if(dp[i]!=INT_MAX)return dp[i];
    int a = INT_MAX;
    for(int it = 0 ; it < k ; it++){
    	if(i<n-(it+1))
    		a = min(a,fun(arr,i+it+1,n,k,dp)+abs(arr[i] - arr[i+it+1]));
    }
	return dp[i] = min(a,dp[i]);
}

int main(){
  int n,k;
  cin>>n>>k;
  vector<int>arr;
  for(int i = 0 ; i < n ; i++){
    int x;
    cin>>x;
    arr.emplace_back(x);
  }
  vector<int>dp(n,INT_MAX);
  cout<<fun(arr,0,n,k,dp);
}
