// Problem - Given a string, you need to print all subsequences of the 
// string sorted by length and lexicographic sorted order is length is same.

#include <bits/stdc++.h>
using namespace std;

void subsequences(string s, string out, vector<string> &v){
    // base case
    if(s.length() == 0){
        v.push_back(out);
        return;
    }

    // Recursive case
    char ch = s[0];
    string reduced_input = s.substr(1);
    subsequences(reduced_input, out + ch, v);
    subsequences(reduced_input, out, v);
}

bool compare(string s1, string s2){
    if(s1.length() == s2.length())
        return s1 < s2;
    return s1.length() < s2.length();
}

int main() {
    string s;
    cin >> s;
    vector<string> v;
    string output = "";
    subsequences(s, output, v);
    sort(v.begin(), v.end(), compare);
    for(string x: v)
        cout << x << ", ";
}
