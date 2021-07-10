// Problem - Given two strings, one big string and one small string. Find the smallest window
// in the big string that contains all the characters of the small string.

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e){
    int i = s;
    int mid = (s+e)/2;
    int j = mid + 1;
    vector<int> temp;

    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
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
    return;
}
void mergesort(vector<int> &arr, int s, int e){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    return merge(arr, s, e);
}


int main() {
    vector<int> arr{10,5,2,0,7,6,4};
    int s = 0;
    int e = arr.size() - 1;
    mergesort(arr,s,e);

    for(int x: arr){
        cout << x << " ";
    }
}
