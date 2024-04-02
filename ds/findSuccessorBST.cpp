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


bstNode *search(bstNode *root, int data) {
    if (root == NULL) return root;
    if (root->data == data) return root;
    else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

bstNode *FindMin(bstNode *root) {
    if (root->left == nullptr) {
        return root;
    } else {
        return FindMin(root->left);
    }
}

bstNode *findSuccessor(bstNode *root, int data) {
    bstNode *current = search(root, data);
    if (current == nullptr) return nullptr;
//    case 1: node has a right subtree
    if (current->right != nullptr) {
        return FindMin(current->right);
    }
//    case 2: node does not have a right subtree
    else {
        bstNode *successor = nullptr;
        bstNode *ancestor = root;
        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else
                ancestor = ancestor->right;
        }
        return successor;
    }
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
    bstNode *temp = findSuccessor(root, 19);
    std::cout << temp->data;
}