#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }

    void push(char x) {
        Node* t = new Node;
        if (t == nullptr) {
            cout << "Stack Overflow\n";
        } else {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    char pop() {
        char x = -1;
        if (top == nullptr) {
            cout << "Stack Underflow\n";
        } else {
            Node* t = top;
            top = top->next;
            x = t->data;
            delete t;
        }
        return x;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    char stackTop() {
        if (top) return top->data;
        return -1;
    }
};

bool isBalanced(string exp) {
    Stack stk;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stk.push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (stk.isEmpty()) return false;
            char top = stk.pop();
            if ((exp[i] == ')' && top != '(') ||
                (exp[i] == '}' && top != '{') ||
                (exp[i] == ']' && top != '[')) {
                return false;
            }
        }
    }
    return stk.isEmpty();
}

int main() {
    string expression;
    cin>>expression;
    if (isBalanced(expression)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }
    return 0;
}
