#include<bits/stdc++.h>
using namespace std;
int lcs(string &s1, string &s2, int n ,int m)
{
    vector<int> prev(n+1, 0), curr(n+1, 0);
    int ans = 0;
    
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1; j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                curr[j] = 1 + prev[j-1];
                ans = max(ans , curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}
int main() {

    string word1 = "leetcode";
    string word2 = "etco";

    int n = word1.size();
    int m = word2.size();

    int size = lcs(word1, word2, n ,m);

    // cout<<size<<endl;
    cout<<(n+m-2*size);
}
