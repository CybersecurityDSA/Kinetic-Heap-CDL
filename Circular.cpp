%%writefile circular.cpp

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
    void Delf() {
    	if (head == nullptr) {
    		cout << "Null node present" << endl;
    		return;
		}

        Node* Del = head->next;
        if (head->next == head) 
            head = nullptr;
		else {
            head->prev = Del->prev;
            Del->prev->next = head;
        }
        delete Del;
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
	}
	
	void Deln() {
		if (head == nullptr) {
    		cout << "Null node present" << endl;
    		return;
		}
		int d;
        cout << "Enter the value of the node to detele:";
        cin >> d;
        
		Node* current = head;
        do {
            if (current->data == d) {
                if (current == head) {
                    Delf();
                    return;
                } 
				else if (current->next == head) {
                    Delb();
                    return;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    return;
                }
            }
            current = current->next;
        } while (current != head);
	}
      
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
            Delf();
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
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert with key"<<endl;
        cout << "3. Traverse Forward" << endl;
        cout << "4. Traverse Backward" << endl;
        cout << "5. Search" << endl;
        cout<<"6. Delete front"<<endl;
        cout<< "7. Delete back"<<endl;
        cout<< "8. Delete Node"<<endl;  
        cout << "9. Check Empty " << endl;
        cout << "10. Size" << endl;
        cout << "11. Reverse" << endl;
        cout << "12. Clear" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 2:
                int data;
                cout << "Enter data to insert at the position: ";
                cin >> data;
                int key;
                cout << "Enter the key to insert: ";
                cin >> key;
                List.insertAtKey(key, data);
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                List.insertBegin(data);
                break;
            case 3:
                List.traverseForward();
                break;
            case 4:
                List.traverseBackward();
                break;
            case 5:
                cout << "Enter the key to search: ";
                cin >> key;
                node = List.search(key);
                if (node != nullptr)
                    cout << "Key found in the list." << endl;
                else
                    cout << "Key not found in the list." << endl;
                break;
            case 6:
              List.Delf();
              break;
            case 7:
              List.Delb();
              break;
            case 8:
              List.Deln();
              break;
            case 9:
                List.isEmpty();
                break;
            case 10:
                List.size();
                break;
            case 11:
                List.reverse();
                break;
            case 12:
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
