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

bool search(bstNode *root, int data) {
    if (root == NULL) return false;
    if (root->data == data) return true;
    else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int min(bstNode *root) {
    if (root->left == nullptr) {
        return root->data;
    } else {
        return min(root->left);
    }
}

int max(bstNode *root) {
    if (root == nullptr) {
        return -1;
    } else if (root->right == nullptr) {
        return root->data;
    }
    return max(root->right);
}

int findHeight(bstNode *root) {
    if (root == nullptr) {
        return -1;
    } else {
        return std::max(findHeight(root->left), findHeight(root->right)) + 1;
    }
}

int main() {
    bstNode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 15);
    insert(root, 19);
    insert(root, 30);
    bool res = search(root, 12);
    std::cout << "min:" << min(root) << '\n';
    std::cout << "max:" << max(root) << '\n';
    if (res == 1) std::cout << "Found" << '\n';
    else std::cout << " Not Found" << '\n';
    std::cout << "height: " << findHeight(root) << '\n';
}