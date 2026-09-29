#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &arr){
    int n = arr.size();
    int i = 0;
    int j = n-1;
    int maxi = 0;
    while(i<j){
        int ans = min(arr[i], arr[j]) *(j-i);
        maxi = max(maxi , ans);
        if(arr[i] < arr[j]) i++;
        else j--;
        
    }
    return maxi;
}
int main()
{
    vector<int> arr = {1,5,4,3};
    cout<<f(arr)<<endl;
}