#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &arr, int k){
    int lsum = 0, rsum = 0, maxsum = 0;

    for(int i = 0;i<k;i++) lsum+=arr[i];

    maxsum = lsum;

    int ridx = arr.size()-1;

    for(int i = k-1;i>=0;i--){
        lsum = lsum - arr[i];
        rsum = rsum + arr[ridx--];
        maxsum = max(maxsum , lsum+rsum);
    }

    return maxsum;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<maxScore(arr, k);
}