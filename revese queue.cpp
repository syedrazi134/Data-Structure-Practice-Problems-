#include <iostream>

class Queue {
private:
    int* arr;
    int front, rear, capacity;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (rear < capacity) {
            arr[rear++] = value;
        } else {
            std::cout << "Queue is full\n";
        }
    }

    void dequeue() {
        if (front < rear) {
            front++;
        } else {
            std::cout << "Queue is empty\n";
        }
    }

    bool isEmpty() {
        return front == rear;
    }

    int getFront() {
        if (!isEmpty()) {
            return arr[front];
        }
        throw std::out_of_range("Queue is empty");
    }

    int size() {
        return rear - front;
    }

    void reverse() {
        // Reversing the elements of the queue using a temporary array
        int size = this->size();
        int* temp = new int[size];

        // Transfer elements to the temporary array
        for (int i = 0; i < size; i++) {
            temp[i] = arr[front + i];
        }

        // Transfer back to the original queue in reversed order
        for (int i = 0; i < size; i++) {
            arr[front + i] = temp[size - 1 - i];
        }

        delete[] temp; // Clean up temporary array
    }

    void display() {
        for (int i = front; i < rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue q(5);

    // Populate the queue with some numbers
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    std::cout << "Original Queue: ";
    q.display();

    // Reverse the queue
    q.reverse();

    std::cout << "Reversed Queue: ";
    q.display();

    return 0;
}
