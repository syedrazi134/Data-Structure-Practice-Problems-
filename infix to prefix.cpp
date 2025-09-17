#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string reverseString(const string &str) {
    return string(str.rbegin(), str.rend());
}

string infixToPrefix(const string &infix) {
    stack<char> s;
    string postfix;
    string reversedInfix = reverseString(infix);

    for (char &c : reversedInfix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == ')') {
            s.push(c);
        } else if (c == '(') {
            while (!s.empty() && s.top() != ')') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the ')'
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) > precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return reverseString(postfix);
}

int main() {
    string infixExpression;
    cout << "Enter infix expression: ";
    getline(cin, infixExpression);

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix expression: " << prefixExpression << std::endl;

    return 0;
}
