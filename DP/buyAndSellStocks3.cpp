#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, int n, int buy, int cap){
    if(cap == 0) return 0;
    if(n == prices.size()) return 0;
    int profit = 0;
    if(buy){
        return max(-prices[n] + solve(prices, n+1, 0, cap), 
                        0+ solve(prices, n+1, 1, cap));
    }
    else{
        return max( prices[n] + solve(prices, n+1, 1 ,cap-1),
                        0 + solve(prices, n+1, 0, cap));
    }
}

//Mem
int solveMem(vector<int> &prices, int n, int buy, int cap, vector<vector<vector<int>>> &dp){
    if(cap == 0) return 0;
    if(n == prices.size()) return 0;

    if(dp[n][buy][cap] != -1) return dp[n][buy][cap];
    int profit = 0;
    if(buy){
        return dp[n][buy][cap] = max(-prices[n] + solveMem(prices, n+1, 0, cap, dp), 
                        0+ solveMem(prices, n+1, 1, cap, dp));
    }
    else{
        return dp[n][buy][cap] = max( prices[n] + solveMem(prices, n+1, 1 ,cap-1, dp),
                        0 + solveMem(prices, n+1, 0, cap, dp));
    }
}

//Tab
int solveTab(vector<int> &prices){

    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n+1,
        vector<vector<int>>(2, vector<int>(3,0))
    );

    for(int i = n-1; i >= 0; i--){

        for(int buy = 0; buy <= 1; buy++){

            for(int cap = 1; cap <= 2; cap++){

                if(buy){

                    dp[i][buy][cap] = max(
                        -prices[i] + dp[i+1][0][cap],
                         0 + dp[i+1][1][cap]
                    );

                }
                else{

                    dp[i][buy][cap] = max(
                         prices[i] + dp[i+1][1][cap-1],
                         0 + dp[i+1][0][cap]
                    );
                }
            }
        }
    }

    return dp[0][1][2];
}
int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (3,-1)));
    cout<<solve(prices, 0 , 1, 2)<<endl;
    cout<<solveMem(prices, 0, 1, 2, dp)<<endl;
    cout<<solveTab(prices)<<endl;
}