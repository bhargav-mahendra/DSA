#include<bits/stdc++.h>
using namespace std;


int solve(string &s, int k)
{
    int n = s.size();
    int ans = 0;
    for(int i = 0 ; i<n;i++)
    {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for(int j = i; j<n;j++)
        {
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            int replacement = (j-i+1) - maxFreq;
            if(replacement <= k){
                ans = max(ans, j-i+1);
            }
        }
    }
    return ans;
}

int solveOP(string &s, int k)
{
    int n = s.size();
    int left = 0;
    int ans = 0;

    unordered_map<char, int> mp;

    int maxFreq = 0;   

    for(int right = 0; right < n; right++)
    {
        mp[s[right]]++;

        maxFreq = max(maxFreq, mp[s[right]]);

        while((right - left + 1) - maxFreq > k)
        {
            mp[s[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}


int main()
{
    string s = "AABABBA";
    int k = 1;
    cout<<solve(s, k)<<endl;
    cout<<solveOP(s, k)<<endl;
}