#include <iostream>

using namespace std;

class Stack {
    static const int size = 10; // Compile-time constant
    int arr[size];
    int head;

public:
    Stack(): head(-1) {} // Initialize head in the initializer list

    ~Stack() {}

    void push(int x) {
        if (head >= size - 1) { // Adjust condition to prevent overflow
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++head] = x;
    }

    void pop() {
        if (head < 0) {
            cout << "No element to remove" << endl;
            return;
        }
        head--;
    }

    bool isEmpty() {
        return head == -1;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // or throw an exception
        }
        return arr[head];
    }
    void print(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack: ";
        for( int i=0; i <= head;i++ ){
            cout << arr[i];
            cout << ", ";
        }
        cout << endl;
    }
};

int main(){
    Stack stack;
    stack.push(10);
    stack.pop();
    stack.print();
    stack.pop();
    stack.isEmpty();
    stack.print();
    stack.push(12);
    stack.push(14);
    stack.print();
    int top = stack.top();
    cout << top;
    return 0;
}