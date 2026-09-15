#include<bits/stdc++.h>
using namespace std;

//Recursion
int solveRec(vector<int> &arr, int n){
    if(n==0) return 0;
    if(n==1) return arr[0];
    int take = arr[n-1] + solveRec(arr, n-2);
    int notTake = solveRec(arr, n-1);
    return max(take , notTake);
}

//Memorization 
int solveMem(vector<int> &arr, int n, vector<int> &dp){
    if(n==0) return 0;
    if(n==1) return arr[0];
    if(dp[n] != -1) return dp[n];
    int take = arr[n-1] + solveRec(arr, n-2);
    int notTake = solveRec(arr, n-1);
    return dp[n] = max(take , notTake);
}

//Tabulation
int solveTab(vector<int> &arr, int n){
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = arr[0];
    for(int i = 2;i <= n;i++){
        int take = arr[i-1] + dp[i-2];
        int nottake = dp[i-1];
        dp[i] = max(take, nottake);
    }
    return dp[n];
}

//space optimization
int solveSO(vector<int> &arr, int n) {
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    int prev2 = 0;       // dp[i-2]
    int prev1 = arr[0];  // dp[i-1]

    for(int i = 2; i <= n; i++) {
        int take = arr[i-1] + prev2;
        int nottake = prev1;

        int curr = max(take, nottake);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
int main(){
    vector<int> arr = {6, 7, 1, 3, 8, 2, 4};
    int n = arr.size();
    vector<int> dp(n+1, -1);
    cout<<solveRec(arr, n)<<endl;
    cout<<solveMem(arr, n, dp)<<endl;
    cout<<solveTab(arr, n)<<endl;
    cout<<solveSO(arr, n)<<endl;
}