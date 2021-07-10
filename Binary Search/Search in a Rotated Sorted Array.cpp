// Write a function that takes input an sorted array of distinct integers, 
// which is rotated about a pivot point and find the index of any given element.
#include <bits/stdc++.h>
using namespace std;

int rotated(vector<int> a, int key){
    int n = a.size();
    int s = 0;
    int e = n - 1;

    while(s <= e){
        int mid = (s + e)/2;
        if(a[mid] == key)
            return mid;
        
        if(a[s] <= a[mid]){
            if(key >= a[s] && key <= a[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else{
            if(key <= a[e] && key >= a[mid])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {7,9,10,1,2,3,4,5,6};
    int key = 6;
    cout << rotated(arr, key);
}
