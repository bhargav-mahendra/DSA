#include <iostream>
#include <vector>
using namespace std;

int countSubSetsRec(int i, int tar, vector<int> &arr)
{
    if(tar == 0) return 1;
    if(i == 0) return arr[0] == tar;

    int notTake = countSubSetsRec(i-1, tar, arr);
    int take = 0;
    if(arr[i] <= tar){
        take = countSubSetsRec(i-1, tar - arr[i], arr);
    }

    return take + notTake;
}

//Memorization
int countSubSetsMem(int i , int tar, vector<int> &arr, vector<vector<int>> &dp)
{
    if(tar == 0) return 1;
    if(i == 0) return arr[i] == tar;
    if(dp[i][tar] != -1) return dp[i][tar];

    int notTake = countSubSetsMem(i-1, tar, arr, dp);
    int take = 0;
    if(arr[i] <= tar){
        take = countSubSetsMem(i-1, tar - arr[i], arr, dp);
    }

    return dp[i][tar] = take+notTake;
}

//tabulation
int countSubSetsTab(int tar, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar+1,-1));
    for(int i = 0;i<n;i++){
        dp[i][0] = 1;
    }
    dp[0][arr[0]] = 1;

    for(int i = 0; i<n;i++){
        for(int sum = 1; sum<=tar;sum++){
            int nottake = dp[i-1][sum];
            int take = 0;
            if(arr[i] <= sum){
                take = dp[i-1][sum - arr[i]];
            }
            dp[i][sum];
        }
    }
    return dp[n-1][tar];
}

//space optimization

int main()
{
    vector<int> arr = {5,2,3,10,6,8};
    int n = arr.size();
    int target = 10;
    vector<vector<int>> dp(n, vector<int>(target+1,-1));
    // cout << countSubSetsRec(n-1, target, arr);
    cout << countSubSetsMem(n-1, target, arr, dp);
    return 0;
}