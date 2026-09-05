#include <iostream>
#include <vector>
using namespace std;

int countSubSets(int i, int tar, vector<int> &arr)
{
    if(tar == 0) return 1;
    if(i == 0) return arr[0] == tar;

    int notTake = countSubSets(i-1, tar, arr);
    int take = 0;
    if(arr[i] <= tar){
        take = countSubSets(i-1, tar - arr[i], arr);
    }

    return take + notTake;
}

int main()
{
    vector<int> arr = {5,2,3,10,6,8};
    int n = arr.size();
    int target = 10;

    cout << countSubSets(n-1, target, arr);

    return 0;
}