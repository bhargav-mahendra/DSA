#include <bits/stdc++.h>
using namespace std;

int coinChangeRec(int n, int tar, vector<int> &arr)
{
    if(tar == 0)
        return 1;

    if(n < 0)
        return 0;

    int nottake = coinChangeRec(n - 1, tar, arr);

    int take = 0;

    if(arr[n] <= tar)
    {
        take = coinChangeRec(n, tar - arr[n], arr);
    }

    return take + nottake;
}


//memorization
int coinChangeMem(int n, int tar, vector<int> &arr, vector<vector<int>>&dp)
{
    if(tar == 0)
        return 1;

    if(n < 0)
        return 0;
    if(dp[n][tar] != -1) return dp[n][tar];
    int nottake = coinChangeMem(n - 1, tar, arr, dp);

    int take = 0;

    if(arr[n] <= tar)
    {
        take = coinChangeMem(n, tar - arr[n], arr, dp);
    }

    return dp[n][tar] =  take + nottake;
}

//tabulation
int coinChangeTab(int tar, vector<int>& arr)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    // Base case: using only arr[0]
    for(int t = 0; t <= tar; t++)
    {
        if(t % arr[0] == 0)
            dp[0][t] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        for(int t = 0; t <= tar; t++)
        {
            int notTake = dp[i - 1][t];
            int take = 0;
            if(arr[i] <= t)
                take = dp[i][t - arr[i]];

            dp[i][t] = notTake + take;
        }
    }

    return dp[n - 1][tar];
}

int main()
{
    vector<int> arr = {1, 2, 5};
    int target = 5;

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int> (target+1, -1));

    cout << coinChangeRec(n - 1, target, arr);
    cout << coinChangeMem(n - 1, target, arr, dp);

    return 0;
}