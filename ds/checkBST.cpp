#include <iostream>


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

bool IsBSTUtil(bstNode *root, int min, int max) {
    if (root == nullptr) return true;
    if (root->data > min && root->data < max &&
        IsBSTUtil(root->left, min, root->data) &&
        IsBSTUtil(root->right, root->data, max)
            )
        return true;
    else
        return false;
}

bool isBST(bstNode *root) {
    return IsBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    bstNode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 15);
    insert(root, 19);
    insert(root, 5);
    insert(root, 9);
    insert(root, 8);
    insert(root, 40);
    bool res = isBST(root);
    std::cout << res << "\n";
}