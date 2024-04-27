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
        count++;
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
        count++;
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
    void Delf() {
    if (head == nullptr) {
        cout << "Null node present" << endl;
        return;
    }
    Node* Del = head;
    if (head->next == head) {
        head = nullptr;
    } else {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    }
    delete Del;
    count--;
}


    void Delb() {
        if (head == nullptr) {
            cout << "Null node present" << endl;
            return;
        }
        Node* Del = head->prev;
        if (head->next == head)
            head = nullptr;
        else {
            head->prev = Del->prev;
            Del->prev->next = head;
        }
        delete Del;
        count--;
    }

    void Deln(int d) {
        if (head == nullptr) {
            cout << "Null node present" << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->data == d) {
                if (current == head) {
                    Delf();
                    return;
                } else if (current->next == head) {
                    Delb();
                    return;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    return;
                }
                count--;
            }
            current = current->next;
            
        } while (current != head);
    }

    // Traversal
    void traverseForward() {
        if (head == nullptr)
            return;
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    void traverseBackward() {
        if (head == nullptr)
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

    int sizev1() {
        return count;
    }
    int size(){
    if (head == nullptr)
        return 0;

    int size = 0;
    Node* current = head;
    do {
        size++;
        current = current->next;
    } while (current != head);

    return size;

    }

    void clear() {
        while (!isEmpty()) {
            Delf();
        }
    }

    void reverse() {
        if (!head) {
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
    List.insertEnd(20);
    List.insertEnd(30);
    List.insertEnd(40);
    List.insertEnd(50);
    List.insertEnd(60);
    List.insertEnd(70);
    List.insertEnd(80);
    cout << "Initial list: ";
    List.traverseForward();
    // Test Case 1: Insert at the end
    List.insertEnd(90); // Passed
    cout << "Inserted 90 at end: ";
    List.traverseForward();

    // Test Case 2: Insert at the beginning
    List.insertBegin(10); // Passed
    cout << "Insert 10 at beginning: ";
    List.traverseForward();

    // Test Case 3: Delete from front
    List.Delf(); // Passed
    cout << "Delete from front: ";
    List.traverseForward();
    // Test Case 4: Delete from back
    cout << "List before deletion (Deletion from back): ";
    List.traverseForward();
    List.Delb(); // Passed
    cout << "Delete from back: ";
    List.traverseForward();
    // Test Case 5: Delete by value
    cout << "List before deletion: ";
    List.traverseForward();
    List.Deln(70);
    cout << "Delete 70 (middle element): "; //Passed
    List.traverseForward();
    List.Deln(20);
    cout << "Delete 20 (first element): "; //Passed
    List.traverseForward();
    // Test Case 6: Traversal
    cout << "Forward traversal: ";
    List.traverseForward(); // Passed
    cout << "Backward traversal: ";
    List.traverseBackward(); // Passed

    // Test Case 7: Search

    Node* foundNode = List.search(80);
    if (foundNode)
        cout << "Node found with value " << foundNode->data << endl; // Passed
    else
        cout << "Node not found" << endl;
    Node* notFoundNode = List.search(100);
    if (notFoundNode)
        cout << "Node found with value " << notFoundNode->data << endl; // Passed
    else
        cout << "Node not found with value " << 100 << endl;

    // Test Case 8: Utility Operations
    cout << "List is empty: " << (List.isEmpty() ? "true" : "false") << endl; // Passed
    cout << "Size of the list: " << List.size() << endl; // Failed (it only tells the max of size of list)

    // Test Case 9: Reverse
    List.reverse(); // Failed
    cout << "List after reversing: ";
    List.traverseForward();
    return 0;
}
