//https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
using namespace std;

int fun(int i, int j, int n, vector<vector<int>>&mat, vector<vector<int>>&dp){
	if(i>=n or j<0 or j>2)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int a=0,b=0;
	if(j==0){
		a = fun(i+1,j+1,n,mat,dp)+mat[i][j];
		b = fun(i+1,j+2,n,mat,dp)+mat[i][j];
	}

	if(j==1){
		a = fun(i+1,j-1,n,mat,dp)+mat[i][j];
		b = fun(i+1,j+1,n,mat,dp)+mat[i][j];
	}
	if(j==2){
		a = fun(i+1,j-1,n,mat,dp)+mat[i][j];
		b = fun(i+1,j-2,n,mat,dp)+mat[i][j];
	}
	return dp[i][j] = max(a,b);
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>>mat;
	for(int i = 0 ; i < n ; i++){
		vector<int>t;
		int x;
		for(int j = 0 ; j < 3 ; j++){
			cin>>x;
			t.emplace_back(x);
		}
		mat.emplace_back(t);
	}
	vector<vector<int>>dp(n,vector<int>(3,-1));
	int ans=0;
	for(int j = 0 ; j < 3 ; j++){
		int a=0,b=0;
		if(j==0){
			a = fun(1,j+1,n,mat,dp)+mat[0][j];
			b = fun(1,j+2,n,mat,dp)+mat[0][j];
		}
		if(j==1){
			a = fun(1,j-1,n,mat,dp)+mat[0][j];
			b = fun(1,j+1,n,mat,dp)+mat[0][j];
		}
		if(j==2){
			a = fun(1,j-1,n,mat,dp)+mat[0][j];
			b = fun(1,j-2,n,mat,dp)+mat[0][j];
		}
		ans = max(ans,max(a,b));
	}
	cout<<ans;
}
