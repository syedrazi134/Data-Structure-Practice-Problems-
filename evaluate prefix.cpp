#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int evaluatePrefix(const string &prefix) {
    stack<int> s;
    int length = prefix.length();

    // Iterate through the prefix expression from right to left
    for (int i = length - 1; i >= 0; --i) {
        char c = prefix[i];

        // Skip spaces
        if (c == ' ') continue;

        // If the character is a digit, extract the complete number
        if (isdigit(c)) {
            int num = 0;
            int base = 1;

            // Handle multi-digit numbers
            while (i >= 0 && isdigit(prefix[i])) {
                num = (prefix[i] - '0') * base + num;
                base *= 10;
                i--;
            }
            s.push(num);
            i++; 
        } else { 
            int operand1 = s.top(); s.pop();
            int operand2 = s.top(); s.pop();
            int result;

            switch (c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': result = std::pow(operand1, operand2); break;
                default: throw std::invalid_argument("Invalid operator");
            }

            s.push(result);
        }
    }

    return s.top(); // The final result will be at the top of the stack
}

int main() {
    string prefixExpression;
    cout << "Enter prefix expression: ";
    getline(cin, prefixExpression);

    try {
        int result = evaluatePrefix(prefixExpression);
        cout << "Result: " << result << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
