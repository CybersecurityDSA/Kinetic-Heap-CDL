
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

       // Utility Operations
    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return count;
    }

    void clear() {
        while (!isEmpty()){
            deleteFront();
        } 
    }

    void reverse() {
        if (!head){
             return;            
        }
        Node* current = head;
        do {
            swap(current->prev, current->next);
            current = current->prev;
        } while (current != head);
        head = head->prev;
    }


};

int main() {
    CDL List;
    int choice, data;
    Node* node;

    do {
        cout << "Circular Doubly Linked List Operations:" << endl;
        cout << "8. Traverse Forward" << endl;
        cout << "9. Traverse Backward" << endl;
        cout << "10. Check Empty " << endl;
        cout << "11. Size" << endl;
        cout << "12. Reverse" << endl;
        cout << "13. Clear" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 8:
                List.traverseForward();
                break;
            case 9:
                List.traverseBackward();
                break;
            case 10:
                List.isEmpty();
                break;
            case 11:
                List.size();
                break;
            case 12:
                List.reverse();
                break;
            case 13:
                List.clear();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}