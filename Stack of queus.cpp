#include <iostream>
#include <queue>
using namespace std;

class StackOfQueues {
private:
    std::queue<int>* queues;
    int capacity;
    int currentQueue;

public:
    StackOfQueues(int size) {
        capacity = size;
        queues = new queue<int>[capacity];
        currentQueue = 0;
    }

    void push(int value) {
        if (currentQueue >= capacity) {
            throw out_of_range("Stack of queues is full");
        }
        queues[currentQueue].push(value);
    }

    int pop() {
        if (currentQueue < 0) {
            throw out_of_range("Stack is empty");
        }

        if (queues[currentQueue].empty()) {
            currentQueue--;
        }

        if (currentQueue < 0) {
            throw out_of_range("Stack is empty");
        }

        int value = queues[currentQueue].front();
        queues[currentQueue].pop();

        if (queues[currentQueue].empty() && currentQueue > 0) {
            currentQueue--;
        }

        return value;
    }

    void display() {
        for (int i = 0; i <= currentQueue; i++) {
            cout << "Queue " << i << ": ";
            queue<int> temp = queues[i];
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    StackOfQueues s(5); // Set capacity for the stack of queues

    s.push(1);
    s.push(2);
    s.push(3);
    s.display();

    cout << "Popped: " << s.pop() << endl;
    s.display();

    return 0;
}
