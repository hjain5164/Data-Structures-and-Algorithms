// Problem - Given an array, find the minimum length subarray that equal to a target sum.

#include <bits/stdc++.h>
using namespace std;

pair<int, int> subarrays(int *arr, int n, int target){
    int i = 0;
    int j = 0;
    int current_sum = 0;
    int min_len_subarray = n + 1;
    pair<int, int> result;
    while(j < n){
        current_sum += arr[j];
        j++;

        while(current_sum > target && i < j){
            current_sum -= arr[i];
            i++;
        }

        if(current_sum == target){
            int length = j - i;
            if(length < min_len_subarray){
                min_len_subarray = length;
                result.first = i;
                result.second = j - 1;
            }
        }
    }
    return result;
}

int main() {
    int arr[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(arr)/sizeof(int);
    int target = 8;
    pair<int, int> result = subarrays(arr, n, target);
    cout << result.first << "-" << result.second << endl;
    return 0;
}
