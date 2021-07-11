// Given a number N and a modern phone keypad. Find out all possible
// strings generated using that number.

#include <bits/stdc++.h>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i = 0){
    if(input[i] == '\0'){
        cout << output << "\n";
        return;
    }

    int current_digit = input[i] - '0';
    if(current_digit == 0 || current_digit == 1){
        printKeypadOutput(input, output, i + 1);
    }
    for(int k = 0; k < keypad[current_digit].size(); k++){
        printKeypadOutput(input, output + keypad[current_digit][k], i + 1);
    }

    return;
}

int main() {
    string input = "234";
    string output;

    printKeypadOutput(input, output, 0);
    return 0;
}
