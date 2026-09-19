#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &fruits){
    int n = fruits.size();
    int ans = 0;
    for(int i = 0; i<n;i++){
        set<int> st;
        for(int j = i; j<n;j++)
        {
            st.insert(fruits[j]);
            if(st.size()>2) break;
            ans = max(ans, j-i+1);
        }
    }
    return ans;
}

int fO(vector<int> &fruits){
    int n = fruits.size();
        int left = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(int right = 0;right < n; right++)
        {
            mp[fruits[right]]++;
            while(mp.size()>2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) 
                {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans , right - left + 1);
        }
        return ans;
}

int main()
{
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout<<f(fruits)<<endl;
    cout<<fO(fruits)<<endl;

}