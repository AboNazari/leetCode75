#include "iostream"

using namespace std;

struct Node {
    int data;
    Node* link;
};

void appendNode(Node** head, int newData){

    Node* newNode = new Node();
    newNode -> data = newData;
    newNode -> link = nullptr;

    if(*head == nullptr){
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last -> link != nullptr){
        last  = last -> link;
    }
    last -> link = newNode;

}


int main(){
    Node* A;
    A = nullptr;

    appendNode(&A, 2);
    appendNode(&A, 4);
    appendNode(&A, 6);


    Node* temp = A;
    cout << "List of Elements in list: " << endl;

    while (temp != nullptr){
        cout << temp -> data << endl;
        temp = temp -> link;
    }

}