#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>&arr, int tar){
    for(int i = 0;i<arr.size();i++){
        for(int j = i+1; j<arr.size();j++){
            if(arr[i] + arr[j] == tar){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

//two pointer
//O(nxlogn)
vector<int> twoSumTp(vector<int> &arr, int tar){
   
    vector<pair<int,int>> nums;

    for(int i = 0; i < arr.size(); i++)
    {
        nums.push_back({arr[i], i});
    }

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;

    while(left < right)
    {
        int sum = nums[left].first + nums[right].first;

        if(sum == tar)
        {
            return {nums[left].second, nums[right].second};
        }

        if(sum > tar)
            right--;
        else
            left++;
    }

    return {-1, -1};
}
//hash map
//O(n)
vector<int> twoSumHm(vector<int> &arr, int tar)
{
    unordered_map<int,int> mp;
    for(int i = 0;i<arr.size();i++)
    {
        int rem = tar - arr[i];
        if(mp.find(rem) != mp.end()){
            return {mp[rem], i};
        }
        mp[arr[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> arr = {2,7,11,15};
    int tar = 9;
    vector<int> ans = twoSumTp(arr, tar);

    for(int x : ans) {
        cout << x << " ";
    }
}