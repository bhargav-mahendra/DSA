#include<bits/stdc++.h>
using namespace std;

int catalansRec(int n){
    if(n == 1 || n == 0) return 1;
    int ans = 0;
    for(int i = 0; i<n;i++)
    {
        ans += catalansRec(i) * catalansRec(n-i-1);
    }
    return ans;
}

int catalansMem(int n, vector<int> &dp){
    if(n==1 || n==0) return 1;
    int ans = 0;

    if(dp[n] != -1) return dp[n];

    for(int i = 0; i<n;i++)
    {
        ans += catalansMem(i, dp) * catalansMem(n-i-1, dp);
    }
    return dp[n] = ans;
}

int catalansTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i<=n;i++){
        for(int j = 0; j<i;j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}


int main(){
    int n = 4;
    vector<int> dp(n+1, -1);
    cout<<catalansRec(n)<<endl;
    cout<<catalansMem(n, dp)<<endl;
    cout<<catalansTab(n)<<endl;
}