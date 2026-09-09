#include<bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string &s, string &t) {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m+1), curr(m+1);
        for(int j = 0;j<=m;j++) prev[j] = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(curr[j-1], prev[j]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }   
int main()
{
    string s = "bbabcbcab";
    string t = s; 

    reverse(t.begin(), t.end());
    cout<<longestPalindromeSubseq(s, t);
}