#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to swap nodes
void swapNodes(Node*& head, int x, int y) {
    if (x == y) return;

    Node *prevX = nullptr, *currX = head;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    Node *prevY = nullptr, *currY = head;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY) return;

    if (prevX) prevX->next = currY;
    else head = currY;

    if (prevY) prevY->next = currX;
    else head = currX;

    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

// Function to insert a new node at the end
void append(Node*& head, int new_data) {
    Node* new_node = new Node();
    Node* last = head;
    new_node->data = new_data;
    new_node->next = nullptr;

    if (!head) {
        head = new_node;
        return;
    }

    while (last->next) last = last->next;
    last->next = new_node;
}

// Function to print the linked list
void printList(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 15);
    append(head, 12);
    append(head, 13);
    append(head, 20);
    append(head, 14);

    cout << "Original list: ";
    printList(head);

    int x, y;
    cout << "Enter two values to swap: ";
    cin >> x >> y;

    swapNodes(head, x, y);

    cout << "Modified list: ";
    printList(head);

    return 0;
}
