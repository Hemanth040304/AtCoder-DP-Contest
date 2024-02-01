//https://atcoder.jp/contests/dp/tasks/dp_a?lang=en

#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>&arr, int i, int n, vector<int>&dp){
    if(i>n)return 0;
    if(i==n-1)return 0;
    if(dp[i]!=INT_MAX)return dp[i];
    int a = INT_MAX;
    if(i<n-1)
    	a = fun(arr,i+1,n,dp)+abs(arr[i] - arr[i+1]);
    int b = INT_MAX;
    if(i<n-2)
    	b = fun(arr,i+2,n,dp)+abs(arr[i]-arr[i+2]);
    return dp[i] = min(a,b);
}

int main(){
  int n;
  cin>>n;
  vector<int>arr;
  for(int i = 0 ; i < n ; i++){
    int x;
    cin>>x;
    arr.emplace_back(x);
  }
  vector<int>dp(n,INT_MAX);
  cout<<fun(arr,0,n,dp);
}
