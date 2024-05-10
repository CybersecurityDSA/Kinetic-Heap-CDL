#include <iostream>
#include <vector>
#include<climits>
#include <functional>

using namespace std;

struct Node {
    int key;
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int certificate;
    int certificateTime;

    Node(int k, int d) : key(k), data(d), left(nullptr), right(nullptr), parent(nullptr), certificate(0), certificateTime(INT_MAX) {}
};

// Certificate event
struct CertificateEvent {
    Node* node;
    int time;

    CertificateEvent(Node* n, int t) : node(n), time(t) {}

    bool operator<(const CertificateEvent& other) const {
        return time > other.time;
    }
};

class KineticHeap {
private:
    vector<Node*> heap;

public:
     // Insert an element into the kinetic heap
    void insert(int key, int data) {
        Node* newNode = new Node(key, data);
        heap.push_back(newNode);
        heapifyUp(heap.size() - 1);
    }

    // Update using key into the kinetic heap

    void updateKey(Node* nodeToUpdate, int newKey) {
        if (!nodeToUpdate) 
            return;

        nodeToUpdate->key = newKey;
        int index = distance(heap.begin(), find(heap.begin(), heap.end(), nodeToUpdate));
        int parent = (index - 1) / 2;
        
        if (parent >= 0 && heap[parent]->key > heap[index]->key)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    // Find the maximum element of the kinetic heap
    Node* findMax() {
        if (heap.empty()){
            return nullptr;            
        } 
        return heap.front();
    }
  // Delete the maximum element from the kinetic heap
    void deleteMax() {
        if (heap.empty()) return;

        delete heap.front();
        heap.front() = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
   void deleteElement(Node* nodeToDelete) {
        if (!nodeToDelete) return;

        auto it = std::find(heap.begin(), heap.end(), nodeToDelete);
        if (it != heap.end()) {
            delete *it;
            *it = heap.back();
            heap.pop_back();
            heapifyDown(std::distance(heap.begin(), it));
        }
    }
    // Heapify up operation
    void heapifyUp(int idx) {
        int parent = (idx-1)/2;
        if (parent >=0 && heap[parent]->key < heap[idx]->key) {
            swap(heap[parent],heap[idx]);
            heapifyUp(parent);
        }
    }
    // Heapify down operation
    void heapifyDown(int idx) {
      int largest = idx;
      int left = 2 * idx + 1;
      int right = 2 * idx + 2;
    
      if (left < heap.size() && heap[left]->key > heap[largest]->key)
        largest = left;
      else if (left < heap.size() && heap[left]->key == heap[largest]->key && heap[left]->certificate > heap[largest]->certificate)
        largest = left;
    
      if (right < heap.size() && heap[right]->key > heap[largest]->key)
        largest = right;
      else if (right < heap.size() && heap[right]->key == heap[largest]->key && heap[right]->certificate > heap[largest]->certificate)
        largest = right;
    
      if (largest != idx) {
        swap(heap[idx], heap[largest]);
        heapifyDown(largest);
      }
}


    // Print the kinetic heap
    void printHeap() {
        if (heap.empty()){
          cout<<"Heap is empty"<<endl;
        }
        vector<Node*>::iterator it;
        for (auto it = heap.begin(); it != heap.end(); ++it) {
        std::cout << "Key: " << (*it)->key << ", Data: " << (*it)->data << "\n";
        }
    }

    // Advance time in the kinetic heap
    void advanceTime(int time) {
        for (Node* node : heap) {
            node->certificateTime -= time;
            if (node->certificateTime <= 0) {
                node->certificate = 0;
            }
        }
    }

    //to fetch given node(for delete function)
   Node* getele() {
    if (heap.empty()) return nullptr;
        return heap.back();
   }
   void printCertificateTime(Node* node) {
    if (node) {
        cout << "Certificate Time for Node with Key " << node->key << ": " << node->certificateTime << endl;
    } else {
        cout << "Node is nullptr" << endl;
    }
}


   //destructor
   ~KineticHeap() {
        for (Node* node : heap) {
            delete node;
        }
    }


};

int main() {
    KineticHeap kheap;

    // Test Case 1: Insert elements into the kinetic heap
    kheap.insert(20, 1);
    kheap.insert(35, 2);
    kheap.insert(13, 3);
    kheap.insert(40, 4);
    kheap.insert(25, 5);
    kheap.printHeap();
//Output 
// Key: 40, Data: 4
// Key: 35, Data: 2
// Key: 13, Data: 3
// Key: 20, Data: 1
// Key: 25, Data: 5
    

    // Test Case 2: Find the maximum element of the kinetic heap
    // output :Max Node: Key = 40, Data = 4
    Node* maxNode = kheap.findMax();
    if (maxNode)
        cout << "Max Node: Key = " << maxNode->key << ", Data = " << maxNode->data << "\n";

    // Test Case 3: Print the initial heap
    cout << "Initial Heap:\n";
    kheap.printHeap();

//Output 
// Key: 40, Data: 4
// Key: 35, Data: 2
// Key: 13, Data: 3
// Key: 20, Data: 1
// Key: 25, Data: 5

    // Test Case 4: Delete all node from the heap
    Node* nodeToDelete = kheap.getele();
    cout << "Node to delete: " << nodeToDelete->key << endl;
    if (nodeToDelete) {
        int key =nodeToDelete->key;
        kheap.deleteElement(nodeToDelete);
        cout << "After deleting node with key " << key << ":\n";
        kheap.printHeap();
    } else {
        cout << "Node to delete is null";
    }
 nodeToDelete = kheap.getele();
    cout << "Node to delete: " << nodeToDelete->key << endl;
    if (nodeToDelete) {
        int key =nodeToDelete->key;
        kheap.deleteElement(nodeToDelete);
        cout << "After deleting node with key " << key << ":\n";
        kheap.printHeap();
    } else {
        cout << "Node to delete is null";
    }
     nodeToDelete = kheap.getele();
    cout << "Node to delete: " << nodeToDelete->key << endl;
    if (nodeToDelete) {
        int key =nodeToDelete->key;
        kheap.deleteElement(nodeToDelete);
        cout << "After deleting node with key " << key << ":\n";
        kheap.printHeap();
    } else {
        cout << "Node to delete is null";
    }
     nodeToDelete = kheap.getele();
    cout << "Node to delete: " << nodeToDelete->key << endl;
    if (nodeToDelete) {
        int key =nodeToDelete->key;
        kheap.deleteElement(nodeToDelete);
        cout << "After deleting node with key " << key << ":\n";
        kheap.printHeap();
    } else {
        cout << "Node to delete is null";
    }
     nodeToDelete = kheap.getele();
    cout << "Node to delete: " << nodeToDelete->key << endl;
    if (nodeToDelete) {
        int key =nodeToDelete->key;
        kheap.deleteElement(nodeToDelete);
        cout << "After deleting node with key " << key << ":\n";
        kheap.printHeap();
    } else {
        cout << "Node to delete is null";
    }
// Output
// Key: 40, Data: 4
// Key: 35, Data: 2
// Key: 13, Data: 3
// Key: 20, Data: 1
// Key: 25, Data: 5
// Node to delete: 25
// After deleting node with key 25:
// Key: 40, Data: 4
// Key: 35, Data: 2
// Key: 13, Data: 3
// Key: 20, Data: 1
// Node to delete: 20
// After deleting node with key 20:
// Key: 40, Data: 4
// Key: 35, Data: 2
// Key: 13, Data: 3
// Node to delete: 13
// After deleting node with key 13:
// Key: 40, Data: 4
// Key: 35, Data: 2
// Node to delete: 35
// After deleting node with key 35:
// Key: 40, Data: 4
// Node to delete: 40
// After deleting node with key 40:
// Heap is empty

    // Test Case 5: Advance time in the kinetic heap
    // Print initial certificate time
    Node* node = kheap.findMax();
    kheap.printCertificateTime(node);

    // Advance time by 5 units
    kheap.advanceTime(5);

    // Print updated certificate time
    kheap.printCertificateTime(node);
// // output 
// Certificate Time for Node with Key 40: 2147483647
// Certificate Time for Node with Key 40: 2147483642

    // Test Case 6: Heapify down operation
    kheap.heapifyDown(2);
    cout << "Heap after heapify down operation:\n";
    kheap.printHeap();
    // output
// Heap after heapify down operation:
// Key: 40, Data: 4
// Key: 35, Data: 2
// Key: 13, Data: 3
// Key: 20, Data: 1
// Key: 25, Data: 5

    return 0;
}
