// Problem - Given a string, write a function to find the largest substring
// with unique characters (no duplicates)
#include <bits/stdc++.h>
using namespace std;

string unique_substring(string str){
    int i = 0;
    int j = 0;
    int window_length = 0;
    int max_window_length = 0;
    int start_window = -1;

    unordered_map<char, int> map;
    while(j < str.length()){
        char ch = str[j];
        if(map.count(ch) && map[ch] >= i){
            i = map[ch] + 1;
            window_length = j - i;
        }
        map[ch] = j;
        window_length++;
        j++;

        if(window_length > max_window_length){
            max_window_length = window_length;
            start_window = i;
        }
    }
    return str.substr(start_window,max_window_length);
}
int main() {
    string str = "abcabe";

    cout << unique_substring(str);
}
