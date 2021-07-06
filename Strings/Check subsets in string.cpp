// Given two non-empty strings, write a function that determines whether the 
// second string is subsequences of the first one.

#include <bits/stdc++.h>
using namespace std;

bool checkSubsets(string s1, string s2){
    int i = s1.length() - 1;
    int j = s2.length() - 1;

    while(i >=0 && j >= 0){
        if(s2[j] == s1[i]){
            j--;
            i--;
        }
        else{
            i--;
        }
    }
    if(j == -1)
        return true;
    
    return false;
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << checkSubsets(s1,s2);
    return 0;
}
