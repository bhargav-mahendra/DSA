#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int target)
{
    unordered_map<int, int> mp;
    int count = 0;

    for(int x : arr)
    {
        int rem = target - x;

        if(mp.find(rem) != mp.end())
        {
            count += mp[rem];
        }

        mp[x]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {-1, 1, 5, 5, 7};
    int target = 6;

    cout << countPairs(arr, target);

    return 0;
}