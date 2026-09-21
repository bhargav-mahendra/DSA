#include<bits/stdc++.h>
using namespace std;

string minWindow(string &s, string &t)
{
    int n = s.size();
    int m = t.size();
    int minLen = INT_MAX;
    string ans = "";
    for(int i = 0; i<n;i++)
    {
        unordered_map<char, int> mp;
        for(auto it:t) mp[it]++;
        int count = 0;
        for(int j = i; j<n;j++)
        {
            if(mp[s[j]] > 0)
            {
                count++;
            }
            mp[s[j]]--;
            if(count == t.size())
            {
                int len = j-i+1;
                if(len < minLen){
                    minLen = len;
                    ans = s.substr(i, len);
                }
                break;
            }
        }
    }
    return ans;
}
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<minWindow(s, t)<<endl;
}