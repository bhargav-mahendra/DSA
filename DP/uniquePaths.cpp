#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(int n, int m)
{
    if(n == 0 && m == 0){
        return 1;
    }
    if(n<0 || m<0) return 0;

    int left = solve(n, m-1);
    int up = solve(n-1, m);
    return left + up;
}

//Memorization
int solveMem(int n, int m, vector<vector<int>>&dp){
    if(n == 0 && m == 0){
        return 1;
    }
    if(n<0 || m<0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    int left = solveMem(n, m-1, dp);
    int up = solveMem(n-1, m ,dp);
    return dp[n][m] = left + up;
}

//Tabulation
int solveTab(int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1 , 0));
    dp[0][0] = 1;
    for(int i = 1;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int j = 1;j<=m;j++){
        dp[0][j] = 1;
    }
    
    for(int i = 1; i <= n;i++){
        for(int j = 1; j<=m;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n][m];
}
int main()
{
    int n = 2;
    int m = 3;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout<< solve(n-1, m-1)<<endl;
    cout<< solveMem(n-1, m-1, dp)<<endl;
    cout<<solveTab(n-1, m-1)<<endl;
}