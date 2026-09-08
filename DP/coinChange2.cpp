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