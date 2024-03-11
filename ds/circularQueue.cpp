#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int *queue;
    int capacity;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        front = size = 0;
        rear = capacity - 1; // Important for the enQueue operation logic
    }

    ~CircularQueue() {
        delete[] queue;
    }

    // Function to add an element to the queue.
    // It changes rear and size
    bool enQueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return false;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        cout << value << " enqueued to queue\n";
        return true;
    }

    // Function to remove an element from queue.
    // It changes front and size
    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN; // Return minimum int value as error code
        }
        int item = queue[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    // Function to get front of queue
    int Front() {
        if (isEmpty()) return INT_MIN;
        return queue[front];
    }

    // Function to get rear of queue
    int Rear() {
        if (isEmpty()) return INT_MIN;
        return queue[rear];
    }

    // Function to check if queue is full
    bool isFull() {
        return (size == capacity);
    }

    // Function to check if queue is empty
    bool isEmpty() {
        return (size == 0);
    }
};

// Demonstration
int main() {
    CircularQueue q(5);

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    cout << q.deQueue() << " dequeued from queue\n";

    q.enQueue(50);
    q.enQueue(60);

    cout << "Front item is " << q.Front() << endl;
    cout << "Rear item is " << q.Rear() << endl;

    return 0;
}
