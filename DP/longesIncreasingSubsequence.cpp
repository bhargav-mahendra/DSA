#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int cnt = 1;
    for(int i = 0; i<nums.size();i++)
    {
        int count = 1;
        int k = i;
        for(int j = i; j<nums.size();j++)
        {
            if(nums[j] > nums[k]){
                count++;
                k = j;
            }
        }
        cnt = max(cnt, count);
    }
    return cnt;
}

int solveRec(vector<int> &nums ,int i , int prev)
{
    if(i == nums.size()) return 0;
    int notTake = 0 + solveRec(nums, i+1 ,prev);
    int take = 0;
    if(prev == -1||nums[prev] < nums[i]){
        take = 1+solveRec(nums ,i+1, i);
    }
    return max(take, notTake);
}

int solveMem(vector<int> &nums, int i, int prev, vector<vector<int>> &dp)
{
    if(i == nums.size()) return 0;

    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int notTake = 0 + solveMem(nums, i+1 ,prev, dp);

    int take = 0;
    if(prev == -1||nums[prev] < nums[i]){
        take = 1+solveMem(nums ,i+1, i, dp);
    }
    return dp[i][prev+1] = max(take, notTake);
}

int solveTab(vector<int> &nums)
{   
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {

        for (int prev = i - 1; prev >= -1; prev--) 
        {

            // Don't take
            int notTake = dp[i + 1][prev + 1];

            // Take
            int take = 0;

            if (prev == -1 || nums[i] > nums[prev]) 
            {
                take = 1 + dp[i + 1][i + 1];
            }

            dp[i][prev + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
}

int solveSp(vector<int>&nums)
{
    int n = nums.size();
    int maxi = 1;
    vector<int> dp(n,1);
    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<i;j++)
        {
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i] , 1+dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
    cout<<solve(nums)<<endl;
    cout<<solveRec(nums, 0, -1)<<endl;
    cout<<solveMem(nums, 0, -1, dp)<<endl;
}