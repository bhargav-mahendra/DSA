#include<bits/stdc++.h>
using namespace std;

//recursion
int knapSackRec(vector<int> &val, vector<int> &wt, int w, int n){
    if(n == 0 || w == 0) return 0;
    int itemWt = wt[n-1];
    int itemVal = val[n-1];
    if(itemWt <= w){
        int ans1 = itemVal + knapSackRec(val , wt, w - itemWt, n-1);
        int ans2 = knapSackRec(val, wt, w, n-1);
        return max(ans2, ans1);
    }
    return knapSackRec(val, wt, w, n-1);
}

//memorization
int knapSackMem(vector<int> &val, vector<int> &wt, int w, int n, vector<vector<int>> &dp){
    if(n == 0 || w == 0) return 0;
    int itemWt = wt[n-1];
    int itemVal = val[n-1];
    if(dp[n][w] != 0) return dp[n][w];
    if(itemWt <= w){
        int ans1 = itemVal + knapSackMem(val , wt, w - itemWt, n-1, dp);
        int ans2 = knapSackMem(val, wt, w, n-1, dp);
        dp[n][w] = max(ans2, ans1);
    }else{
        dp[n][w] = knapSackMem(val, wt, w, n-1, dp);
    }
    return dp[n][w];
}

//tabulation
int knapSackTab(vector<int> &val, vector<int> &wt, int w, int n){
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=w;j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];
            if(itemWt <= j){
                int ans1 = itemVal + dp[i-1][j-itemWt];
                int ans2 = dp[i-1][j];
                dp[i][j] = max(ans1, ans2);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

//space optimization 
int knapSackSO(vector<int> &val, vector<int> &wt, int w, int n){
    vector<int> prev(w+1, 0) , curr(w+1 ,0);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=w;j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];
            if(itemWt <= j){
                int ans1 = itemVal + prev[j-itemWt];
                int ans2 = prev[j];
                curr[j] = max(ans1, ans2);
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[w];
}

int main(){
    vector<int> val = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 2, 3};
    int w = 5;
    int n = val.size();
    vector<vector<int>> dp(n+1, vector<int> (w+1, 0));
    cout<<knapSackRec(val, wt, w, n)<<endl;
    cout<<knapSackMem(val , wt, w, n ,dp)<<endl;
    cout<<knapSackTab(val , wt, w, n )<<endl;
    cout<<knapSackSO(val , wt, w, n )<<endl;
}