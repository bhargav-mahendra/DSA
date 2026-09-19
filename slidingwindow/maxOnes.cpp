#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &nums , int k){
    int n = nums.size();
    int maxlen = 0;
    for(int i = 0;i<n;i++)
    {
        int zeroes = 0;
        for(int j = i; j<n;j++)
        {
            if(nums[j] == 0) zeroes++;
            if(zeroes>k){
                break;
            }
            maxlen = max(maxlen, j-i+1);
        }
    }
    return maxlen;
}

int fO(vector<int> &nums , int k )
{
    int n = nums.size();
    int left = 0;
    int zeroes = 0;
    int maxlen = 0;
    for(int right = 0;right < n; right++)
    {
        if(nums[right] == 0) zeroes++;
        while(zeroes > k){
            if(nums[left] == 0) zeroes--;
            left ++;
        }
        maxlen = max(maxlen , right - left + 1);
    }
    return maxlen;
}
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0} ;
    int k = 2;
    cout<<f(nums, k)<<endl;
    cout<<fO(nums ,k);
}