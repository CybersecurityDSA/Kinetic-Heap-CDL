
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
        if (parent >=0 && heap[parent]->key > heap[idx]->key) {
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
        if (right < heap.size() && heap[right]->key > heap[largest]->key)
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

   //destructor
   ~KineticHeap() {
        for (Node* node : heap) {
            delete node;
        }
    }


};

int main() {
    KineticHeap kheap;

    kheap.insert(20, 1);
    kheap.insert(35, 2);
    kheap.insert(13, 3);
    kheap.insert(40, 4);
    kheap.insert(25, 5);

    Node* maxNode = kheap.findMax();
    if (maxNode)
        cout << "Max Node: Key = " << maxNode->key << ", Data = " << maxNode->data << "\n";

    cout << "Initial Heap:\n";
    kheap.printHeap();

    Node* nodeToDelete = kheap.getele();
    cout << "Node to delete: " << nodeToDelete->key << endl;
    if (nodeToDelete) {
        kheap.deleteElement(nodeToDelete);
        cout << "After deleting node with key " << nodeToDelete->key << ":\n";
        kheap.printHeap();
    } else {
        cout << "Node to delete is null";
    }

    kheap.advanceTime(10);
    kheap.heapifyDown(0);
    cout << "Heap after heapify down operation:\n";
    kheap.printHeap();

    return 0;
}
