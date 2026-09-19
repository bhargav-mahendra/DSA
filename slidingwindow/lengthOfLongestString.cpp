#include<bits/stdc++.h>
using namespace std;

int solve(string &s)
{
    int n = s.size();
    int maxlen = 0;
    for(int i = 0; i<n;i++)
    {
        unordered_map<char , int> mp;
        for(int j = i; j<n;j++)
        {
            if(mp.find(s[j]) != mp.end())
            {
                break;
            }
            mp[s[j]]++;
            maxlen = max(maxlen, j-i+1);
        }
    }
    return maxlen;
}

int solveOptimal(string &s)
{
    int n = s.size();
    int maxlen = 0;
    unordered_map<char , int> mp;
    int left = 0;
    for(int right = 0; right < n; right++)
    {
        if(mp.find(s[right]) != mp.end()){
            left = max(left, mp[s[right]] + 1);
        }
        mp[s[right]] = right;
        maxlen = max(maxlen, right - left + 1);
    }
    return maxlen;
}
int main(){
    string s = "cadbzabcd";
    cout<<solve(s)<<endl;
    cout<<solveOptimal(s);
}