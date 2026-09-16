#include<bits/stdc++.h>
using namespace std;

//recursion
bool solveRec(string &s, string &p , int i, int j){
    if(i<0 && j<0) return true;
    if(j < 0 && i > 0) return false;
    if(i<0 && j>0){
        for(int k = 0; k<=j;k++){
            if(p[k] != '*') return false;
        }
        return true;
    }

    if(s[i] == p[j] || p[j] == '?') return solveRec(s, p, i-1, j-1);
    if(p[j] == '*'){
        return solveRec(s, p, i-1, j) || solveRec(s, p, i, j-1);
    }
    return false;
}

// Memorization
bool solveMem(string &s, string &p, int i, int j, vector<vector<bool>>&dp){
    if(i < 0 && j < 0) return true;
    if(j < 0 && i > 0) return false;
    if(i < 0 && j > 0){
        for(int k = 0; k <= j;k++){
            if(p[k] != '*') return false;
        }
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == p[j] || p[j] == '?') return dp[i][j] = solveMem(s, p, i-1, j-1, dp);
    if(p[j] == '*'){
        return dp[i][j] = solveMem(s, p, i-1, j, dp) || solveMem( s,p, i, j-1, dp);
    }
    return dp[i][j] = false;
}

//Tabulation
bool solveTab(string &s, string &p, int n, int m){
    vector<vector<bool>> dp(n+1, vector<bool>(m+1,0));
    dp[0][0] = true;
    for(int j = 1;j <= m;j++){
        if(p[j-1] == '*'){
            dp[0][j] = dp[0][j-1];
        }
        else{
            dp[0][j] = false;
        }
    }
    for(int i = 1; i <= n;i++){
        for(int j = 1; j<=m;j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            if(p[j-1] == '*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s = "abcd";
    string p = "ab*?";
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    cout<<solveRec(s, p, n-1, m-1)<<endl;
    cout<<solveMem(s, p, n-1, m-1, dp)<<endl;
    cout<<solveTab(s, p, n, m)<<endl;

}