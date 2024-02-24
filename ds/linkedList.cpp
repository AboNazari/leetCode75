#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *next;
};

void add(Node **head, int newData) {
//    allocate an empty node in memory and assign new data to it
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node *last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;

}


void insert(Node **head, int newData, int n) {
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (n == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *last = *head;
    for (int i = 0; i < n - 2; i++) {
        last = last->next;
    }
    newNode->next = last->next;
    last->next = newNode;

}

void reverse(Node **head) {
    Node *prev, *current, *next;
    current = *head;
    prev = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void reverseUtil(Node *current, Node *prev, Node **head) {
    if (current == nullptr) {
        *head = prev;
        return;
    }

    Node *next = current->next;
    current->next = prev;
    prev = current;
    reverseUtil(next, prev, head);
}


void recursiveRevers(Node **head, Node *current) {

    //    to use a helper function for recursion
    //    reverseUtil(*head, nullptr, head);

    //check if after next link of this node is null
    if (current->next == nullptr) {
        *head = current;
        return;
    }

    // Pass head everytime, change current to next link
    recursiveRevers(head, current->next);

    // when last recursive call is done, the state returns to one before last node in the chain
    Node *next = current->next;
    next->next = current;
    current->next = nullptr;

}


void deleteNode(Node **head, int position) {
    Node *temp = *head;
    Node *temp2;

    if (position == 1) {
        *head = temp->next;
        delete temp;
        return;
    }

    for (int i = 0; i < position - 1; i++) {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    delete temp;
}


void print(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        cout << "  ";
        temp = temp->next;
    }
}


int main() {
    Node *head;
    head = nullptr;

    add(&head, 2);
    add(&head, 5);
    add(&head, 6);
    insert(&head, 8, 2); // 2 8 5 6
    insert(&head, 10, 1); // 10 2 8 5 6

    deleteNode(&head, 1);

    recursiveRevers(&head, head);
    print(head);
}