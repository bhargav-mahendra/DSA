#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, int n, int buy){
    if(n >= prices.size()) return 0;
    int profit = 0;
    if(buy){
        int buyStock  = -prices[n] + solve(prices, n+1, 0); 
        int skip = solve(prices, n+1, 1);
        profit = max(buyStock, skip);
    }
    else{
        int sell = prices[n] + solve(prices, n+2, 1);
        int skip = solve(prices, n+1, 0);
        profit = max(sell, skip);
    }
    return profit;
}

int solveMem(vector<int> &prices, int n, int buy, vector<vector<int>> &dp){

    if(n >= prices.size()) return 0;
    int profit = 0;
    if(dp[n][buy] != -1) return dp[n][buy];

    if(buy){
        int buyStock  = -prices[n] + solveMem(prices, n+1, 0, dp); 
        int skip = solveMem(prices, n+1, 1, dp);
        profit = max(buyStock, skip);
    }

    else{
        int sell = prices[n] + solveMem(prices, n+2, 1, dp);
        int skip = solveMem(prices, n+1, 0, dp);
        profit = max(sell, skip);
    }

    return dp[n][buy] = profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    cout<<solve(prices, 0 , 1)<<endl;
    cout<<solveMem(prices, 0, 1, dp)<<endl;
}