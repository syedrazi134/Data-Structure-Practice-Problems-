#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class BrowsingHistory {
    struct node {
        string pageTitle;
        string browsingDate;
        node *front;
        node *prev;
    } *head, *tail, *current;

public:
    BrowsingHistory() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addHistory(string title, string date) {
        node *newNode = new node;  // Allocate memory for the new node
        newNode->pageTitle = title;
        newNode->browsingDate = date;
        newNode->prev = NULL;
        newNode->front = NULL;

        if (head == NULL) {
            head = tail = current = newNode;
            return;
        }

        tail->front = newNode;
        newNode->prev = tail;
        tail = newNode;
        current = tail;
    }

    void navigateForward() {
        if (current != NULL && current->front != NULL) {
            current = current->front;
            cout << "\nPage Title: " << current->pageTitle << "\nBrowsing Date: " << current->browsingDate << endl;
        } else {
            cout << "\nThere is no history forward..." << endl;
        }
    }

    void navigateBack() {
        if (current != NULL && current->prev != NULL) {
            current = current->prev;
            cout << "\nPage Title: " << current->pageTitle << "\nBrowsing Date: " << current->browsingDate << endl;
        } else {
            cout << "\nThere is no history backward..." << endl;
        }
    }

    void displayHistory() {
        if (head == NULL) {
            cout << "\nHistory list is empty...." << endl;
            return;
        }
        node *p = head;
        while (p) {
            cout << "\nPage Title: " << p->pageTitle << "\nBrowsing Date: " << p->browsingDate << endl;
            p = p->front;
        }
    }

    void clearHistory(string period) {
        if (period == "last day") {
            clearHistoryHelper(1);
        } else if (period == "last 7 days") {
            clearHistoryHelper(7);
        } else if (period == "last 4 weeks") {
            clearHistoryHelper(28);
        } else if (period == "all") {
            clearAllHistory();
        } else {
            cout << "\nInvalid Option..." << endl;
        }
    }

    void clearAllHistory() {
        if (head == NULL) {
            cout << "\nThere is no history...." << endl;
            return;
        }

        while (head) {
            node *temp = head;
            head = head->front;
            delete temp;
        }
        head = tail = current = NULL;
    }

    void clearHistoryHelper(int days) {
        int currentDate = 20241110;

        node *temp = head;

        while (temp) {
            if (stoi(temp->browsingDate) < (currentDate - days)) {
                node *toDelete = temp;

                // Handle deleting the node properly and updating pointers
                if (temp->prev) {
                    temp->prev->front = temp->front;
                } else { // We're deleting the head
                    head = temp->front;
                }

                if (temp->front) {
                    temp->front->prev = temp->prev;
                } else { // We're deleting the tail
                    tail = temp->prev;
                }

                temp = temp->front; // Move to the next node
                delete toDelete;    // Delete the node
            } else {
                temp = temp->front;
            }
        }
    }
};

int main() {
    BrowsingHistory hist;
    hist.addHistory("Google", "20240905");
    hist.addHistory("ChatGPT", "20240910");
    hist.addHistory("StackOverflow", "20241108");
    hist.addHistory("GitHub", "20241029");
    hist.addHistory("Reddit", "20241015");

    cout << "All History: " << endl;
    hist.displayHistory();

    cout << "\nNavigating Back: " << endl;
    hist.navigateBack();

    cout << "\nNavigating Forward: " << endl;
    hist.navigateForward();

    // Clear history for different periods
    cout << "\nClearing History (last 7 days): " << endl;
    hist.clearHistory("last 7 days");
    
    hist.displayHistory();

    return 0;
}
