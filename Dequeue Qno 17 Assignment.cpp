#include<iostream>
using namespace std;

class Deque {
    struct node {
        int data;
        node* next;
        node* prev;
    }*front, *rear;

public:
    void PUSH(int);
    int POP();
    void Inject(int);
    int Eject();
    void display();
    
    Deque() {
        front = NULL;
        rear = NULL;
    }
};

// Insert item X at the front end of DEQUE
void Deque::PUSH(int value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;
    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }
    cout << "PUSH: " << value << endl;
}

// Remove and return the front item from DEQUE
int Deque::POP() {
    if (front == NULL) {
        cout << "Deque is empty. Cannot POP." << endl;
        return -1;
    }
    int value = front->data;
    node* temp = front;
    front = front->next;
    if (front != NULL) {
        front->prev = NULL;
    } else {
        rear = NULL;
    }
    delete temp;
    cout << "POP: " << value << endl;
    return value;
}

// Insert item X at the rear end of DEQUE
void Deque::Inject(int value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Inject: " << value << endl;
}

// Remove and return the rear item from DEQUE
int Deque::Eject() {
    if (rear == NULL) {
        cout << "Deque is empty. Cannot Eject." << endl;
        return -1;
    }
    int value = rear->data;
    node* temp = rear;
    rear = rear->prev;
    if (rear != NULL) {
        rear->next = NULL;
    } else {
        front = NULL;
    }
    delete temp;
    cout << "Eject: " << value << endl;
    return value;
}

// Function to display the current state of the deque
void Deque::display() {
	if(front == NULL){
		cout<<"\nDeque is empty...."<<endl;
		return;
	}
    node* current = front;
    cout << "Current Deque: ";
    while (current != NULL) {
        cout << current->data << ",";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Deque deque;

    deque.PUSH(10);
    deque.Inject(20);
    deque.PUSH(30);
    deque.Inject(40);
    deque.display();

    deque.POP();
    deque.Eject();
    deque.display();

    deque.POP();
    deque.POP(); // This should indicate the deque is empty
    deque.display();

    return 0;
}
