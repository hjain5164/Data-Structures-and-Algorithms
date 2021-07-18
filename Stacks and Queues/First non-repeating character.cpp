// Give a running stream of characters. You need to output the first non-repeating
// character in the string formed so far, after getting every new character in the 
// input. Print -1 if no such character exists.

#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<char> q;
    int freq[27] = {0};
    char ch;
    while(cin >> ch){
        q.push(ch);
        freq[ch - 'a']++;
        while(!q.empty()){
            int idx = q.front() - 'a';
            if(freq[idx] > 1)
                q.pop();
            else{
                cout << q.front() << endl;
                break;
            }
        }
        if(q.empty())
            cout << "-1" << endl;
    }
}

