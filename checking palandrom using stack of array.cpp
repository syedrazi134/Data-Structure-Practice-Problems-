#include <iostream>
#include <cstring>

class ArrayStack {
private:
    char* arr;
    int top;
    int capacity;

public:
    ArrayStack(int size) {
        arr = new char[size];
        capacity = size;
        top = -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(char c) {
        if (top < capacity - 1) {
            arr[++top] = c;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0'; // Return null char if stack is empty
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isPalindromeUsingArrayStack(const std::string& str) {
    ArrayStack stack(str.length());

    for (char c : str) {
        stack.push(c);
    }

    for (char c : str) {
        if (stack.pop() != c) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string str = "racecar";
    std::cout << "Is \"" << str << "\" a palindrome? " << (isPalindromeUsingArrayStack(str) ? "Yes" : "No") << std::endl;
    return 0;
}
