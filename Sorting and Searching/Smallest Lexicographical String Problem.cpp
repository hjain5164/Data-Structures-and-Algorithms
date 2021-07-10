// Problem - You are given a list of N strings. You need to concatenate them together
// in some order such that the resulting string would be lexicographically smallest. 
// Given the list of strings, output the lexicographically smallest concatenation.
/**
INPUT
3 
a
ab
aba

OUTPUT
aabaab (As this comes first in the dictionary).
*/


#include <bits/stdc++.h>
using namespace std;

bool compare(string x, string y){
    return x + y < y + x;
}

int main() {
    string arr[] = {"a", "ab", "aba"};
    int n = 3;

    sort(arr, arr + n, compare);
    for(auto s: arr)
        cout << s;


}
