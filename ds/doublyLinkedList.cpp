#include <mmcobj.h>
#include "iostream"

using namespace std;


class DoublyLinkedList {
    struct Node {
        int data;
        Node *prev;
        Node *next;

        Node(int x) : data(x), prev(nullptr), next(nullptr) {}
    };

    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    ~DoublyLinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->next;
            delete current; // Reclaim the memory of the current node
            current = next; // Move to the next node
        }
    }

    void add(int x) {
        Node *newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }

    };

    void insertAtHead(int x) {
        Node *newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            newNode->next = temp;
            temp->prev = newNode;
            head = newNode;
        }
    };

    void insertAtTail(int x) {
        Node *newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            newNode->prev = temp;
            temp->next = newNode;
        }
    };

    void print() {
        Node *temp = head;
        cout << "The doubly linked List elements: " << endl;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    };

    void printReverse() {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << "Reverse Data order" << endl;
        while(temp != nullptr){
            cout << temp-> data << endl;
            temp = temp -> prev;
        }
    };

};


int main() {
    DoublyLinkedList doublyLinkedList;
    doublyLinkedList.add(10);
    doublyLinkedList.add(2);
    doublyLinkedList.add(5);
    doublyLinkedList.insertAtHead(5);
    doublyLinkedList.insertAtTail(15);

    doublyLinkedList.print();
    doublyLinkedList.printReverse();

    return 0;
}