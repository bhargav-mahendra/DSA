#include<bits/stdc++.h>
using namespace std;

//recursion
int editDistanceRec(string &s, string &t, int i, int j){
    if(i < 0) return j+1;//word1 exhausted
    if(j < 0) return i+1;//word2 exhausted

    if(s[i] == t[j]){
        return editDistanceRec(s, t, i-1, j-1);
    }
    else{
        int insert = editDistanceRec(s, t, i, j-1);
        int deletee = editDistanceRec(s, t, i-1, j);
        int replace = editDistanceRec(s, t, i-1, j-1);
        return 1 + min({insert, deletee, replace});
    }
}

//Memorization
int editDistanceMem(string &s, string &t, int i , int j, vector<vector<int>>&dp){
    if(i < 0) return j+1;//word1 exhausted
    if(j < 0) return i+1;//word2 exhausted
    
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]){
        return dp[i][j] = editDistanceMem(s, t, i-1, j-1, dp);
    }
    else{
        int insert = editDistanceMem(s, t, i, j-1,dp);
        int deletee = editDistanceMem(s, t, i-1, j,dp);
        int replace = editDistanceMem(s, t, i-1, j-1,dp);
        return dp[i][j] = 1 + min({insert, deletee, replace});
    }
}

//Tabulation
int editDistanceTab(string &s, string &t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int j = 0;j <= m; j++){
        dp[0][j] = j;
    }
    for(int i = 0;i <= n; i++){
        dp[i][0] = i;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=m ;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min({
                    dp[i][j-1], 
                    dp[i-1][j],
                    dp[i-1][j-1]
                });
            }
        }
    }
    return dp[n][m];
}

//space optimization
int editDistanceSO(string &s, string &t){
    int n = s.size();
    int m = t.size();
    vector<int> prev(m+1,0), curr(m+1,0);
    for(int j = 0;j <= m; j++){
       curr[j] = j;
    }

    for(int i = 1; i <= n; i++){
        curr[0] = i;
        for(int j = 1; j<=m ;j++){
            if(s[i-1] == t[j-1]){
                curr[j] = prev[j-1];
            }
            else{
                curr[j] = 1 + min({
                    curr[j-1], 
                    prev[j],
                   prev[j-1]
                });
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main(){
    string s = "horse";
    string t = "ros";

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    cout<<editDistanceRec(s, t, n-1, m-1)<<endl;
    cout<<editDistanceMem(s, t, n-1, m-1, dp)<<endl;
}