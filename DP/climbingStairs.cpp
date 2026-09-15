#include<bits/stdc++.h>
using namespace std;

//recursion
int solveRec(int n){
    if(n==1 || n==0) return 1;
    return solveRec(n-1)+solveRec(n-2);
}

//memorization
int solveMem(int n, vector<int> & dp){
    if(n==1 || n==0) return 1;
    if(dp[n] != -1) return dp[n];

    return dp[n] = solveMem(n-1, dp)+solveMem(n-2, dp);
}

//tabulation
int solveTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//space optimization
int solveSO(int n){
    int prev1 = 1;
    int prev2 = 1;
    int curr = 0;
    for(int i = 2;i<=n;i++){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
int main(){
    int n = 4;
    vector<int> dp(n+1, -1);
    cout<<solveRec(n)<<endl;
    cout<<solveMem(n, dp)<<endl;
    cout<<solveTab(n)<<endl;
    cout<<solveSO(n)<<endl;
}