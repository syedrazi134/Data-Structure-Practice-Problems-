#include <iostream>
#include <queue>
using namespace std;

class QueueOfQueues {
private:
    queue<int>* queues;
    int capacity;
    int frontQueue;

public:
    QueueOfQueues(int size) {
        capacity = size;
        queues = new queue<int>[capacity];
        frontQueue = 0;
    }

    void enqueue(int value) {
        if (frontQueue >= capacity) {
            throw out_of_range("Queue of queues is full");
        }
        queues[frontQueue].push(value);
    }

    int dequeue() {
        if (frontQueue < 0 || queues[0].empty()) {
            throw out_of_range("Queue is empty");
        }

        int value = queues[0].front();
        queues[0].pop();

        if (queues[0].empty()) {
            for (int i = 0; i < frontQueue - 1; i++) {
                queues[i] = queues[i + 1]; // Shift queues forward
            }
            frontQueue--;
        }

        return value;
    }

    void display() {
        for (int i = 0; i <= frontQueue; i++) {
            cout << "Queue " << i << ": ";
            queue<int> temp = queues[i];
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout <<endl;
        }
    }
};

int main() {
    QueueOfQueues qq(5); // Set capacity for the queue of queues

    qq.enqueue(1);
    qq.enqueue(2);
    qq.enqueue(3);
    qq.display();

    cout << "Dequeued: " << qq.dequeue() <<endl;
    qq.display();

    return 0;
}
