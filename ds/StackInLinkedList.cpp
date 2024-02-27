#include <iostream>

using namespace std;

class Stack {
    struct Node {
        int data;
        Node *next;
    };
    Node *top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        Node *current = top;
        if (current != nullptr) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void push(int x) {
        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            return;
        }
        Node *current;
        current = top;
        top = current -> next;
        delete current;
    }


    void print() {
        if (top == nullptr) {
            return;
        }
        Node *current = top;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};


int main() {

    Stack stack;
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.print();
    stack.pop();
    stack.print();
    stack.push(3);
    stack.print();


    return 0;
}