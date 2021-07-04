// String tokenization using stringstream object

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    stringstream ss(str);
    string token;
    while(getline(ss, token, ' ')){
        cout << token << endl;
    }
}
