#include<bits/stdc++.h>
using namespace std;

int f(string &s)
{
    int n = s.size();
    if(n < 3) return 0;
    int count = 0;
    for(int i = 0;i<n;i++)
    {   
        int hash[3] = {0};
        
        for(int j = i; j<n;j++)
        {
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1]+hash[2] == 3){
                count++;
            }
        }
    }
    return count;
}

int fO(string &s)
{
    int n = s.size();
    int count = 0;
    int last[3] = {-1,-1,-1};
    for(int i = 0;i<n;i++)
    {
        last[s[i] - 'a'] = i;
        if(last[0] != -1 && last[1] != -1 && last[2] != -1)
        {
            count += min({last[0] , last[1], last[2]})+1;
        }
    } 
    return count;
}
int main()
{
    string s = "bbacba";
    cout<<f(s)<<endl;
    cout<<fO(s)<<endl;
}