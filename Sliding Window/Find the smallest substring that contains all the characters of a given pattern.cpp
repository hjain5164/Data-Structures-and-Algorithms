// Problem - Given two strings, one big string and one small string. Find the smallest window
// in the big string that contains all the characters of the small string.

#include <bits/stdc++.h>
using namespace std;

string stringWindow(string s, string p){
    int FP[256] = {0};
    int FS[256] = {0};

    for(int i = 0; i < p.length(); i++){
        FP[p[i]]++;
    }
    int cnt = 0;
    int start = 0;
    int start_idx = -1;
    int min_so_far = INT_MAX;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        FS[ch]++;

        if(FP[ch] != 0 && FS[ch] <= FP[ch]){
            cnt++;
        }

        if(cnt == p.length()){
            while(FP[s[start]] == 0 || FS[s[start]] > FP[s[start]]){
                FS[s[start]]--;
                start++;
            }
            int window_size = i - start + 1;
            if(window_size < min_so_far){
                min_so_far = window_size;
                start_idx = start;
            } 
        }
    }

    if(start_idx == -1)
        return "No window Found";
    
    return s.substr(start_idx, min_so_far);
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << stringWindow(s,p);
}
