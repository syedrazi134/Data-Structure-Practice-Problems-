#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[10];
    int front;
    int rear;

public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }

    // Function to add an item to the queue
    void enqueue(int value) {
        if ((rear + 1) == 10) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0; // Initialize front on the first enqueue
        }
        rear = (rear + 1) % 10;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Function to remove and return the front item from the queue
    int dequeue() {
        if (front == -1) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int value = arr[front];
        if (front == rear) { 
            front = -1;
            rear = -1;
        } 
        else {
            front = (front + 1) % 10;
        }
        cout << "Dequeued: " << value <<endl;
        return value;
    }

    // Function to display the current state of the queue
    void display() {
        if (front == -1) {
           cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current Queue: ";
        int i = front;
        while (1) {
            cout << arr[i] << ",";
            if (i == rear) break;
            i = (i + 1) % 10;
        }
        cout << endl;
    }

    // Function to get the number of elements in the queue
    int size() {
        if (front == -1) return 0;
        return (rear - front + 10) % 10 + 1;
    }

    // Function to split the queue into two circular queues
    void split(CircularQueue& CQueue1, CircularQueue& CQueue2) {
        if (front == -1) {
            cout << "Queue is empty. Cannot split." << endl;
            return;
        }

        int position = 1; // Start with position 1 (odd)
        int i = front;

        do {
            if (position % 2 == 1) {
                CQueue1.enqueue(arr[i]); // Odd position
            } else {
                CQueue2.enqueue(arr[i]); // Even position
            }
            position++;
            i = (i + 1) % 10;
        } while (i != (rear + 1) % 10);
    }
};

int main() {
    CircularQueue originalQueue;
    originalQueue.enqueue(1);
    originalQueue.enqueue(2);
    originalQueue.enqueue(3);
    originalQueue.enqueue(4);
    originalQueue.enqueue(5);
    originalQueue.enqueue(6);
    originalQueue.enqueue(7);
    originalQueue.enqueue(8);
    originalQueue.enqueue(9);
    originalQueue.enqueue(10);

    cout << "Original Queue: ";
    originalQueue.display();

    CircularQueue CQueue1; // Queue for odd positions
    CircularQueue CQueue2; // Queue for even positions

    originalQueue.split(CQueue1, CQueue2);

    cout << "CQueue1 (Odd Positions): ";
    CQueue1.display();

    cout << "CQueue2 (Even Positions): ";
    CQueue2.display();

    return 0;
}
