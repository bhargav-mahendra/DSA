#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> hash(n);

    int maxi = 1;
    int lastIdx = 0;

    for(int i = 0; i < n; i++)
    {
        hash[i] = i;

        for(int j = 0; j < i; j++)
        {
            if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }

        if(dp[i] > maxi)
        {
            maxi = dp[i];
            lastIdx = i;
        }
    }

    vector<int> temp;

    temp.push_back(nums[lastIdx]);

    while(hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        temp.push_back(nums[lastIdx]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
}

int main()
{
    vector<int> arr = {1, 16, 7, 8, 4};

    vector<int> ans = solve(arr);

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}