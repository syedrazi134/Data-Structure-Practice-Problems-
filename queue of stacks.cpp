#include <iostream>
#include <stack>
using namespace std;

class QueueOfStacks {
private:
    stack<int>* stacks;
    int capacity;
    int currentStack;

public:
    QueueOfStacks(int size) {
        capacity = size;
        stacks = new stack<int>[capacity];
        currentStack = 0;
    }


    void enqueue(int value) {
        if (currentStack >= capacity) {
            throw out_of_range("Queue of stacks is full");
        }
        stacks[currentStack].push(value);
    }

    int dequeue() {
        if (currentStack < 0) {
            throw out_of_range("Queue is empty");
        }

        if (stacks[currentStack].empty()) {
            currentStack--;
        }

        if (currentStack < 0) {
            throw out_of_range("Queue is empty");
        }

        int value = stacks[currentStack].top();
        stacks[currentStack].pop();

        if (stacks[currentStack].empty() && currentStack > 0) {
            currentStack--;
        }

        return value;
    }

    void display() {
        for (int i = 0; i <= currentStack; i++) {
            cout << "Stack " << i << ": ";
            stack<int> temp = stacks[i];
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    QueueOfStacks q(5); // Set capacity for the queue of stacks

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    return 0;
}
