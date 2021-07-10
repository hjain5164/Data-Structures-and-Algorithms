// Problem - Given a sorted array of strings that is interspersed with empty strings. 
// Write a function to find the location of a given string.
/**
INPUT
["ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""]
bat
OUTPUT
4
*/


#include <bits/stdc++.h>
using namespace std;

int sparse_search(vector<string> a, int n, string key){
    int s = 0; 
    int e = n - 1;
    while(s <= e){
        int mid = (s + e)/2;
        int mid_left = mid - 1;
        int mid_right = mid + 1;
        if(a[mid] == ""){
            while(1){
                if(mid_left < s && mid_right > e)
                    return -1;
                else if( mid_right <= e && a[mid_right] != ""){
                    mid = mid_right;
                    break;
                }
                else if( mid_left >= s && a[mid_left] != ""){
                    mid = mid_left;
                    break;
                }
                mid_left--;
                mid_right--;
            }
        }
        if(a[mid] == key)
            return mid;
        else if(a[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}
int main() {

    vector<string> arr{"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""};
    int n = 12;;
    string f = "dog";
    cout <<sparse_search(arr, n, f);

}
