#include <iostream>
using namespace std;

class CircularQueue {
    struct Node {
        int data;
        Node* next;

    }*tail;

public:
    CircularQueue(){
        tail = NULL;
    }

    // Function to add an item to the queue
    void add(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;

        } 
        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Added: " << value <<endl;
    }

    // Function to delete an item from the queue
    int remove() {
        if (tail == NULL) {
            cout << "Queue is empty. Cannot remove." << endl;
            return -1;
        }

        Node* front = tail->next;
        int value = front->data; 

        if (front == tail) {
            delete front;
            tail = nullptr;
        } else {
            tail->next = front->next;
            delete front;
        }
        cout << "Removed: " << value <<endl;
        return value;
    }

    // Function to display the current state of the queue
    void display() {
        if (tail == NULL) {
            cout << "Queue is empty." <<endl;
            return;
        }
        Node* current = tail->next;
        cout << "Current Queue: ";
        do {
            cout << current->data << ",";
            current = current->next;
        } while (current != tail->next);

        cout <<endl;
    }

};

int main() {
    CircularQueue queue;

    queue.add(10);
    queue.add(20);
    queue.add(30);
    queue.display();

    queue.remove();
    queue.display();

    queue.remove();
    queue.remove();
    queue.remove(); // Attempt to remove from an empty queue

    return 0;
}
