// Problem - Write a function that takes an array of distinct integers
// and returns the kth smallest in the array.
//  This condition applies 0 <= K <= N - 1

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int s, int e){
    int i = s - 1;
    int pivot = a[e];
    for(int j = s; j < e; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[e]);
    return i + 1;
}

int quickselect(vector<int> &a, int s, int e, int K){
    if(s >= e)
        return a[s];
    
    int p = partition(a, s, e);
    if(K == p)
        return a[p];
    else if(K > p)
        return quickselect(a, p + 1, e, K);
    else
        return quickselect(a, s , p - 1, K);
}

int main() {
    vector<int> arr{10,5,2,0,7,6,4};
    int n = arr.size();
    int K = 1;
    cout << quickselect(arr, 0, n - 1, K);
}
