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
    insert(root, 1);
    insert(root, 31);
    insert(root, 30);
    levelOrder(root);
}