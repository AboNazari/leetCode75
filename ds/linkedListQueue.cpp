#include <iostream>
using namespace std;

// Node structure representing a single element in the queue
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Queue class using a linked list
class LinkedListQueue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue
    int size;    // Number of elements in the queue

public:
    // Constructor initializes an empty queue
    LinkedListQueue() : front(nullptr), rear(nullptr), size(0) {}

    // Destructor to free the memory used by the queue
    ~LinkedListQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            // If queue is empty, both front and rear are the new node
            front = rear = newNode;
        } else {
            // Add the new node at the end of queue and change rear
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << data << " enqueued to queue\n";
    }

    // Function to remove an element from queue
    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return INT_MIN; // Queue is empty
        }
        Node* temp = front;
        int data = front->data;
        front = front->next;

        if (front == nullptr) {
            // If the queue becomes empty, then change rear also as NULL
            rear = nullptr;
        }

        delete temp;
        size--;
        return data;
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Function to get the front element of the queue
    int peek() const {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return INT_MIN; // Queue is empty
        }
        return front->data;
    }

    // Function to get the size of the queue
    int getSize() const {
        return size;
    }
};

// Demonstration
int main() {
    LinkedListQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.dequeue();
    queue.dequeue();
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    cout << "Queue Front : " << queue.peek() << endl;
    cout << "Queue Size : " << queue.getSize() << endl;

    return 0;
}
