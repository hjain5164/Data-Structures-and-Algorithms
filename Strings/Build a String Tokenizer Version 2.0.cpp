#include <bits/stdc++.h>
using namespace std;

vector<string> mystrtok(string str, char delim){
    vector<string> tokens;
    string temp = "";
    for(int i = 0; i < str.length(); i++){
        if(str[i] == delim){
            tokens.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];           
    }
    tokens.push_back(temp);
    return tokens;
}

int main() {
    string s;
    getline(cin, s);
    vector<string> tokens = mystrtok(s, ' ');
    for(string s: tokens)
        cout << s << endl;
}
