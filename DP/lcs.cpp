#include<bits/stdc++.h>
using namespace std;

//recursion
int lcsRec(string &s1, string &s2,int m,int n) {

    if (m < 0 || n < 0)
        return 0;

    if (s1[m] == s2[n])
        return 1 + lcsRec(s1, s2, m - 1, n - 1);

    else
        return max(lcsRec(s1, s2, m, n - 1), lcsRec(s1, s2, m - 1, n));
}

//Memorization 
int lcsMem(string &s1, string &s2,int m,int n, vector<vector<int>> &dp) {

    if (m < 0 || n < 0)
        return 0;

    if (s1[m] == s2[n])
        return 1 + lcsMem(s1, s2, m - 1, n - 1, dp);

    else
        return max(lcsMem(s1, s2, m, n - 1, dp), lcsMem(s1, s2, m - 1, n, dp));
}

//tabulation
int lcsTab(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int j = 0; j<m;j++){
        dp[0][j] = 0;
    }
    for(int i = 0; i<n;i++){
        dp[i][0] = 0;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

//space optimization
int lcsSO(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,-1), curr(m+1, -1);
    for(int j = 0;j<=m;j++) prev[j] = 0;
    for(int i = 1;i<=n;i++)
    {
        curr[0] = 0;
        for(int j = 1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
            else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }
    return prev[m];
}
int main() {
    string s1 = "adebc";
    string s2 = "dcadb";
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout << lcsRec(s1, s2, m-1 ,n-1) << endl;
    // cout << lcsMem(s1, s2, m-1 ,n-1, dp) << endl;
    //cout<<lcsTab(s1, s2);
    cout<<lcsSO(s1, s2);

    return 0;
}