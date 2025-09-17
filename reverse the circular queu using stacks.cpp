#include <iostream>
#include <stack>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueue(int capacity){
    	front = 0;
    	rear = -1;
    	size = 0;
    	capacity = capacity;
        arr = new int[capacity];
    }


    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    void reverse() {
        stack<int> stack;

        // Push all elements to the stack
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            stack.push(arr[index]);
        }

        // Pop elements from the stack and enqueue them back
        for (int i = 0; i < size; i++) {
            arr[(front + i) % capacity] = stack.top();
            stack.pop();
        }

        // Adjust the rear pointer
        rear = (front + size - 1) % capacity;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << std::endl;
    }
};

int main() {
    CircularQueue queue(5);

    queue.enqueue('a');
    queue.enqueue('b');
    queue.enqueue('c');

    std::cout << "Original Queue: ";
    queue.display();

    queue.reverse();

    std::cout << "Reversed Queue: ";
    queue.display();

    return 0;
}
