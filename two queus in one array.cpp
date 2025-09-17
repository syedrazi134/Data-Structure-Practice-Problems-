#include <iostream>
using namespace std;

class TwoQueues {
private:
    int* arr;
    int size;
    int front1, rear1;
    int front2, rear2;

public:
    TwoQueues(int s) {
        size = s;
        arr = new int[size];
        front1 = -1;
        rear1 = -1;
        front2 = size;
        rear2 = size;
    }

    // Enqueue for first queue
    void enqueue1(int value) {
        if (rear1 + 1 == front2) {
            cout << "Queue 1 is full!" << endl;
            return;
        }
        if (front1 == -1) {
            front1 = 0;
        }
        rear1++;
        arr[rear1] = value;
    }

    // Enqueue for second queue
    void enqueue2(int value) {
        if (rear2 - 1 == rear1) {
            cout << "Queue 2 is full!" << endl;
            return;
        }
        if (front2 == size) {
            front2 = size - 1;
        }
        rear2--;
        arr[rear2] = value;
    }

    // Dequeue for first queue
    int dequeue1() {
        if (front1 == -1 || front1 > rear1) {
            cout << "Queue 1 is empty!" << endl;
            return -1;
        }
        int value = arr[front1];
        front1++;
        return value;
    }

    // Dequeue for second queue
    int dequeue2() {
        if (front2 == size || front2 < rear2) {
            cout << "Queue 2 is empty!" << endl;
            return -1;
        }
        int value = arr[front2];
        front2++;
        return value;
    }

    // Display the queues
    void displayQueues() {
        cout << "Queue 1: ";
        for (int i = front1; i <= rear1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Queue 2: ";
        for (int i = rear2; i < front2; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    TwoQueues queues(10);

    // Enqueue elements in Queue 1
    queues.enqueue1(10);
    queues.enqueue1(20);
    queues.enqueue1(30);

    // Enqueue elements in Queue 2
    queues.enqueue2(40);
    queues.enqueue2(50);
    queues.enqueue2(60);

    // Display both queues
    queues.displayQueues();

    // Dequeue from Queue 1
    cout << "Dequeued from Queue 1: " << queues.dequeue1() << endl;

    // Dequeue from Queue 2
    cout << "Dequeued from Queue 2: " << queues.dequeue2() << endl;

    // Display both queues again
    queues.displayQueues();

    return 0;
}
