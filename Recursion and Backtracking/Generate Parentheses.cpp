// Write a function to generate all possible N pairs of 
// balanced parentheses '(' and ')'.

#include <bits/stdc++.h>
using namespace std;

void generatePairs(string output, int n, int open, int close, int i){
    if(i==2*n){
        cout << output << "\n";
        return;
    }

    if(open < n){
        generatePairs(output+'(', n, open + 1, close, i+1);
    }
    if(close < open){
        generatePairs(output+')', n, open, close + 1, i+1);
    }
}

int main() {
    int N = 3;
    string output;
    generatePairs(output, N, 0, 0, 0);

}
