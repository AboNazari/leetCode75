#include <iostream>
#include <queue>

using namespace std;
struct bstNode {
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode *createBST(int data) {
    auto *newNode = new bstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bstNode *insert(bstNode *root, int data) {
    if (root == NULL) {
        root = createBST(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void preOrder(bstNode *root) {
    if (root == nullptr) return;
    cout << "current: " << root->data << '\n';
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(bstNode *root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << "current: " << root->data << '\n';
    inOrder(root->right);
}

void postOrder(bstNode *root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << "current: " << root->data << '\n';
}

// BFS
void levelOrder(bstNode *root) {
    if (root == nullptr) return;
    queue<bstNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
        bstNode *current = Q.front();
        cout << "current: " << current->data << '\n';
        if (current->left != nullptr) Q.push(current->left);
        if (current->right != nullptr) Q.push(current->right);
        Q.pop();
    }
}

int main() {
    bstNode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 15);
    insert(root, 19);
    insert(root, 5);
    insert(root, 1);
    insert(root, 14);
    insert(root, 7);
    insert(root, 30);
    cout << "pre order: " << '\n';
    preOrder(root);
    cout << "in order: " << '\n';
    inOrder(root);

    cout << "post order: " << '\n';
    postOrder(root);
}