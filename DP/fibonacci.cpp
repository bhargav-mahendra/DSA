#include<bits/stdc++.h>
using namespace std;

//recursion
int f(int n){
    if(n<=1) return n;
    return f(n-1) + f(n-2);
}

//memorization
int fMem(int n, vector<int> &dp)
{
    if(n<=1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fMem(n-1, dp) + fMem(n-2, dp);
}

//tabulation
int fTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    if(n == 0) return dp[0];

    for(int i = 2; i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//space optimization
int fSO(int n){
    int prev1 = 0;
    int prev2 = 1;
    if(n==0) return 0;
    int curr;
    for(int i = 2; i<=n; i++){
        curr = prev1+prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
int main()
{
    int n = 8;
    vector<int> dp(n+1, -1);
    cout<<f(n)<<endl;
    cout<<fMem(n ,dp)<<endl;
    cout<<fTab(n)<<endl;
    cout<<fSO(n)<<endl;
}