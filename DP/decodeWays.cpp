#include<bits/stdc++.h>
using namespace std;
int solve(string &s, int i){
    if(i == s.size()){
        return 1;
    }

    if(s[i] == '0') return 0;
    int onedigit = solve(s, i+1);
    int twodigit = 0;
    if(i+1 < s.size()){
        int num = (s[i] - '0')*10 + (s[i+1] - '0');
        if(num >= 10 && num <= 26){
            twodigit = solve(s, i+2);
        }
    }

    return onedigit + twodigit;
}

//Memorization
int solveMem(string &s, int i, vector<int> &dp){
    if(i == s.size()){
        return 1;
    }

    if(s[i] == '0') return 0;

    if(dp[i] != -1) return dp[i];

    int onedigit = solve(s, i+1);
    int twodigit = 0;
    if(i+1 < s.size()){
        int num = (s[i] - '0')*10 + (s[i+1] - '0');
        if(num >= 10 && num <= 26){
            twodigit = solve(s, i+2);
        }
    }

    return dp[i] = onedigit + twodigit;
}

//Tabulation 
int sovleTab(string &s){
    vector<int> dp(s.size()+1 , 0);

    dp[s.size()] = 1;

    for(int i = s.size() - 1; i >= 0;i--){
        if(s[i] == '0'){
            dp[i] = 0;
            continue;
        }

        dp[i] = dp[i+1];
        if(i+1 < s.size()){
            int num = (s[i] - '0') *10 + (s[i+1] - '0');
            if(num >= 10 && num <= 26){
                dp[i] += dp[i+2];
            }
        }
    }   
    return dp[0];
}

int main()
{
    string s = "226";
    vector<int> dp(s.size(), -1);
    cout<<solve(s, 0)<<endl;
    cout<<solveMem(s, 0 ,dp)<<endl;
    cout<<sovleTab(s);
}