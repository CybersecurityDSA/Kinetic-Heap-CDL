

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

     void insertEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* lastNode = head->prev;
            newNode->next = head;
            newNode->prev = lastNode;
            lastNode->next = newNode;
            head->prev = newNode;
        }
    }
    void insertBegin(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* lastNode = head->prev;
        newNode->next = head;
        newNode->prev = lastNode;
        lastNode->next = newNode;
        head->prev = newNode;
        head = newNode; 
    }
    count++;
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
   Node* search(int key) {
        if (head == nullptr)
            return nullptr;

        Node* current = head;
        do {
            if (current->data == key)
                return current;
            current = current->next;
        } while (current != head);

        return nullptr;
    }

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
        cout << "3. Insert with key"
        cout << "5. Insert at Beginning" << endl;
        cout << "8. Traverse Forward" << endl;
        cout << "9. Traverse Backward" << endl;
        cout << "10.Search" << endl;
        cout << "11. Check Empty " << endl;
        cout << "12. Size" << endl;
        cout << "13. Reverse" << endl;
        cout << "14. Clear" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 3:
                cin
                List.insertAtKey(int key, int data)
            case 5:
                int data;
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                List.insertBegin(data);
                break;
            case 8:
                List.traverseForward();
                break;
            case 9:
                List.traverseBackward();
                break;
            case 10:
                int key;
                cout << "Enter the key to search: ";
                cin >> key;
                node = List.search(key);
                if (node != nullptr)
                    cout << "Key found in the list." << endl;
                else
                    cout << "Key not found in the list." << endl;
                break;
             case 11:
                List.isEmpty();
                break;
            case 12:
                List.size();
                break;
            case 13:
                List.reverse();
                break;
            case 14:
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
