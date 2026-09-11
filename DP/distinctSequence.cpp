#include<bits/stdc++.h>
using namespace std;

//recurision 
int solveRec(string &s, string &t, int i , int j){
    if(j<0) return 1;
    if(i<0) return 0;
    if(s[i] == t[j]){
        return solveRec(s, t, i-1, j-1) + solveRec(s, t, i-1, j);
    }
    return solveRec(s, t, i-1, j);
}

//Memorization
int solveMem(string &s, string &t, int i , int j, vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]){
        return dp[i][j] = solveMem(s, t, i-1, j-1,dp) + solveMem(s, t, i-1, j, dp);
    }
    return dp[i][j] = solveMem(s, t, i-1, j, dp);
}

//Tabualtion 
int solveTab(string &s, string &t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i = 0;i<=n;i++){
        dp[i][0] = 1;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1; j <= m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

//space optimization
int solveSO(string &s, string &t){
    int n = s.size();
    int m = t.size();

    vector<int> prev(m+1, 0), curr(m+1,0);
    prev[0] = curr[0] = 1;
    for(int i = 1; i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                curr[j] = prev[j-1] + prev[j];
            }
            else{
               curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[m];

}
int main() 
{
    string s = "babgbag";
    string t = "bag";
    vector<vector<int>> dp(s.length() , vector<int> (t.size(), -1));
    //cout<< solveRec(s, t, s.length() - 1, t.length() - 1)<<endl;
    //cout<< solveMem(s, t, s.length() - 1, t.length() - 1, dp)<<endl;
    // cout<<solveTab(s, t);
    cout<<solveSO(s, t);
    
}