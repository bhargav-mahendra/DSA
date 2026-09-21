#include<bits/stdc++.h>
using namespace std;

int climbingStairs(int n, vector<int> &cost)
{
    if(n == 0 || n == 1) return cost[n];
    return cost[n] + min(climbingStairs(n-1, cost),
                    climbingStairs(n-2, cost)); 
}

int climbingStairsMem(int n, vector<int> &cost, vector<int>&dp)
{
    if(n == 0 || n == 1) return cost[n];
    if(dp[n] != -1) return dp[n];
    return dp[n] = cost[n] + min(climbingStairsMem(n-1, cost, dp),
                    climbingStairsMem(n-2, cost, dp));
}
int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int n = cost.size();
    vector<int> dp(n,-1);
    cout<<min(climbingStairs(n-1, cost),
            climbingStairs(n-2, cost))<<endl;
    cout<<min(climbingStairsMem(n-1, cost, dp),
            climbingStairsMem(n-2, cost,dp))<<endl;
}