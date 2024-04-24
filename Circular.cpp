%%writefile double.cpp

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class CDL {
private:
    Node* head;
    int count;

public:

    CDL() : head(nullptr), count(0) {}

    // Insertion
    void insertAtKey(int key, int data) {
        Node* current = head;
        while (current != nullptr && current->data != key) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node with key " << key << " not found in the list." << endl;
            return;
        }
    //Deletion

    // Traversal
    void traverseForward() {
        if (head==nullptr)
          return;
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        }while(current!=head);
        cout << endl;
    }

    void traverseBackward() {
        if (head==nullptr)
          return;
        Node* current = head->prev;
        do {
            cout << current->data << " ";
            current = current->prev;
        } while (current != head->prev);
        cout << endl;
    }

    //Search

    // Utility

};

int main() {
    CDL List;
    int choice, data;
    Node* node;

    do {
        cout << "Circular Doubly Linked List Operations:" << endl;
        cout << "3. Insert with key"
        cout << "8. Traverse Forward" << endl;
        cout << "9. Traverse Backward" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 3:
                cin
                List.insertAtKey(int key, int data)
            case 8:
                List.traverseForward();
                break;
            case 9:
                List.traverseBackward();
                break
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}