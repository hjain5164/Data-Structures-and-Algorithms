// Given a string of balanced expression, find out if it contains redundant parenthesis or not.
// A parenthesis is redundant parenthesis if same sub-expression is surrounded by unnecessary or multiple bracekts.
#include <bits/stdc++.h>
using namespace std;

bool check_redundant(string str){
    stack<char> s;
    for(char ch: str){
        if(ch != ')')
            s.push(ch);
        else{
            bool operator_found = false;
            while(!s.empty() && s.top() != '('){
                char top = s.top();
                if(top == '+' || top == '-' || top == '*' || top == '/')
                    operator_found = true;
                s.pop();
            }
            s.pop();
            if(operator_found == false)
                return true;
        }
    }
    return false;
}


int main() {
    string s = "(a+b*(c-d))";
    // string s = "((a+b))";
    if(check_redundant(s))
        cout << "Redundant Parenthesis";
    else
        cout << "Non-redundant Parenthesis";
}
