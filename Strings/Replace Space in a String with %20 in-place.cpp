// Problem - Given a string, replace all the spaces in the string with %20.
// Space Complexity - O(1) and Time Complexity = O(N);

#include <bits/stdc++.h>
using namespace std;

void space20(string &str){
    int n = str.length();
    int spaces = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == ' ')
            spaces++;
    }
    int shifts = spaces * 2;
    int end = n + shifts - 1;
    str.append(end, '\0');
    for(int i = n - 1; i >= 0; i--){
        if(str[i] == ' '){
            str[i + shifts] = '0';
            str[i + shifts - 1] = '2';
            str[i + shifts - 2] = '%';
            shifts -= 2;
        }
        else
            str[i + shifts] = str[i];
    }

    return;
}

int main() {
    string str;
    getline(cin, str, '\0');
    space20(str);
    cout << str;
}
