#include<bits/stdc++.h>
using namespace std;

//recursion
int f(int n){
    if(n<=1) return 0;
    if(n==2 || n == 3) return 1;
    return f(n-1) + f(n-2) + f(n-3);
}

//memorization
int fMem(int n, vector<int> &dp)
{
    if(n<=1) return 0;
    if(n==2 || n == 3) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fMem(n-1, dp) + fMem(n-2, dp)+fMem(n-3, dp);
}

//tabulation
int fTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = dp[3] = 1;

    if(n == 1||n==0) return dp[0];
    if(n == 2||n==3) return dp[0];

    for(int i = 4; i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main()
{
    int n = 8;
    vector<int> dp(n+1, -1);
    cout<<f(n)<<endl;
    cout<<fMem(n ,dp)<<endl;
    cout<<fTab(n)<<endl;
    // cout<<fSO(n)<<endl;
}