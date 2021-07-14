// Given an expression string. Write a program to check if all the pairs of
// parenthesis are valid.

#include <bits/stdc++.h>
using namespace std;

bool check_paranthesis(string str){
    stack<char> s;
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{')
            s.push(ch);
        else if (ch == ')'){
            if(s.top() == '(' && !s.empty())
                s.pop();
            else
                return false;
        }
        else if (ch == ']'){
            if(s.top() == '[' && !s.empty())
                s.pop();
            else
                return false;
        }
        else if (ch == '}'){
            if(s.top() == '{' && !s.empty())
                s.pop();
            else
                return false;
        }
    }
    if(!s.empty())
        return false;
    else
        return true;
}

int main() {
    string expression_1 = "((a+b)*x - d)";
    string expression_2 = "((a+b]+c)*(d-e)";
    string expression_3 = "[[((){{}())]]";
    if(check_paranthesis(expression_3))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;    
}
