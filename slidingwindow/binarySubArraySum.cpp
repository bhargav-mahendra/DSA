#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &nums, int goal)
{
    int n = nums.size();
    int count = 0;
    for(int i = 0; i<n; i++)
    {
        int sum = 0;
        for(int j = i; j<n;j++)
        {
            sum+=nums[j];
            if(sum == goal) count++;
            if(sum > goal) break;
        }
    }
    return count;
}

int atMost(vector<int>& nums, int goal)
{
    if(goal < 0)
        return 0;

    int left = 0;
    int sum = 0;
    int count = 0;

    for(int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while(sum > goal)
        {
            sum -= nums[left];
            left++;
        }

        count += right - left + 1;
    }

    return count;
}

int main()
{
    vector<int> nums = {0,0,0,0,0};
    int goal = 0;
    cout<<f(nums, goal)<<endl; 
    cout<<atMost(nums, goal) - atMost(nums, goal - 1);
}