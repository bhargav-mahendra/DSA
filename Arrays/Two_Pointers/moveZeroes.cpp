#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = arr.size();
    int i = 0;
    while(arr[i] != 0){
        i++;
    }
    int j = i+1;
    while(j<n){
        if(arr[j] != 0){
            swap(arr[i++], arr[j]);
        }
        j++;
    }
    for(int x : arr){
        cout<<x<<" ";
    }
}