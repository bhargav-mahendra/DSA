#include<bits/stdc++.h>
using namespace std;

int solve(string &s, int k)
{
    int n = s.size();
    int ans = 0;
    for(int i = 0; i<n;i++){
        set<char> st;
        for(int j = i; j<n;j++){
            st.insert(s[j]);
            if(st.size() > k){
                break;
            }
            ans = max(ans, j-i+1);
        }
    }
    return ans;
}

int solveOp(string &s, int k)
{
    int n = s.size();
    int ans = 0;
    unordered_map<char, int> mp;
    int left = 0;
    for(int right = 0; right < n; right++)
    {
        mp[s[right]]++;
        while(mp.size() > k){
            mp[s[left]]--;
            if(mp[s[left]] == 0) {
                mp.erase(s[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int solveOOp(string &s, int k)
{
    int n = s.size();
    int ans = 0;
    unordered_map<char, int> mp;
    int left = 0;
    for(int right = 0; right < n; right++)
    {
        mp[s[right]]++;
        if(mp.size() <= k){
            ans = max(ans, right - left + 1);
        }
        if(mp.size() > k){
            mp[s[left]]--;
            if(mp[s[left]] == 0) {
                mp.erase(s[left]);
            }
            left++;
            right++;
        }
    }
    return ans;
}
int main()
{
    string s = "aababbcaacc";
    int k = 2;
    cout<<solve(s, k)<<endl;
    cout<<solveOp(s, k)<<endl;
    cout<<solveOOp(s, k)<<endl;
}