// Problem - Given an array containing integers. You need to 
// count the total number of inversions. Two elements a[i] and a[j]
// form an inversion is a[i] > a[j] and i < j.

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int s, int e){
    int i = s;
    int mid = (s+e)/2;
    int j = mid + 1;
    int inversion = 0;
    vector<int> temp;

    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            inversion += mid - i + 1;
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <=e){
        temp.push_back(arr[j]);
        j++;
    }
    int t = 0;
    for(int k = s; k <= e; k++){
        arr[k] = temp[t++];
    }
    return inversion;
}
int inversion_count(vector<int> &arr, int s, int e){
    if(s >= e){
        return 0;;
    }
    int mid = (s+e)/2;
    int C1 = inversion_count(arr, s, mid);
    int C2 = inversion_count(arr, mid + 1, e);
    int CI = merge(arr, s, e);
    return C1 + C2 + CI;
}


int main() {
    vector<int> arr{10,5,2,0,7,6,4};
    int s = 0;
    int e = arr.size() - 1;
    int inversions = inversion_count(arr,s,e);
    cout << inversions;
}
