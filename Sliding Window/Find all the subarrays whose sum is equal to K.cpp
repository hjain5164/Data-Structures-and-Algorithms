// Problem - Given an array, find all the subarrays that equal to a target sum.

#include <bits/stdc++.h>
using namespace std;

void subarrays(int *arr, int n, int target){
    int i = 0;
    int j = 0;
    int current_sum = 0;

    while(j < n){
        current_sum += arr[j];
        j++;

        while(current_sum > target && i < j){
            current_sum -= arr[i];
            i++;
        }

        if(current_sum == target)
            cout << i << "-" << j - 1 << "\n";
    }
    return;
}

int main() {
    int arr[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(arr)/sizeof(int);
    int target = 8;
    subarrays(arr, n, target);
    return 0;
}
