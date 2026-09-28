#include<bits/stdc++.h>
using namespace std;


int f(int i, int j, vector<int> &arr)
{
    if(i>j) return 0;
    int maxi = INT_MIN;
    for(int k = i;k<=j;k++)
    {
        int cost = arr[i-1]*arr[k]*arr[j+1] + f(i, k-1, arr) + f(k+1,j, arr);
        maxi = max(maxi, cost);
    }
    return maxi;
}

int fMem(int i, int j ,vector<int> &arr, vector<vector<int>> &dp)
{
     if(i > j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int maxi = INT_MIN;

    for(int k = i; k <= j; k++)
    {
        int cost = arr[i-1] * arr[k] * arr[j+1]
                 + fMem(i, k-1, arr, dp)
                 + fMem(k+1, j, arr, dp);

        maxi = max(maxi, cost);
    }

    return dp[i][j] = maxi;
}

int fTab(vector<int>& arr, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for(int i = n; i >= 1; i--)
    {
        for(int j = i; j <= n; j++)
        {
            int maxi = INT_MIN;

            for(int k = i; k <= j; k++)
            {
                int cost = arr[i-1] * arr[k] * arr[j+1]
                         + dp[i][k-1]
                         + dp[k+1][j];

                maxi = max(maxi, cost);
            }

            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}

int maxProductSum(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1)); 
    arr.insert(arr.begin(), 1);
    arr.push_back(1);
    // return fMem(1, n, arr, dp);
    return fTab(arr,n);
    
}
int main()
{
    vector<int> arr = {3,1,5,8};

    cout << maxProductSum(arr) << endl;

    return 0;
}