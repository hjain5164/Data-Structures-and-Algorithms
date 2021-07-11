// Problem - Given a set of non-negative integers and a value sum.
// Determing if there is a subset of the given set with sum equal to given sum.

#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> arr, int n, int i, int X){
    if(i == n){
        if(X == 0)
            return 1;
        return 0;
    }
    int inc = countSubsets(arr, n, i + 1, X - arr[i]);
    int exc = countSubsets(arr, n , i + 1, X);

    return inc + exc;
}

int main() {
    vector<int> arr{1,2,3,4,5};
    int X = 6;

    cout << countSubsets(arr, arr.size(), 0, X);
}
