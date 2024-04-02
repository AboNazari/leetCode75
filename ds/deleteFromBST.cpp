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

bstNode *findMin(bstNode *val) {
    if (val == nullptr) return nullptr;
    else if (val->left == nullptr) {
        return val;
    } else {
        return findMin(val->left);
    }
}


bstNode *Delete(bstNode *root, int data) {
    if (root == nullptr) return nullptr;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else {
        //  case 1: data is a leaf node
        if (root->right == nullptr && root->left == nullptr) {
            delete root;
            root = nullptr;
        }
            // case 2: node has only 1 child
        else if (root->left == nullptr) {
            bstNode *temp = root;
            root = temp->right;
            delete temp;
        } else if (root->right == nullptr) {
            bstNode *temp = root;
            root = temp->left;
            delete temp;
        }
            // case 3: node has two child
        else {
            bstNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
        return root;
    }
}

bool search(bstNode *root, int data) {
    if (root == nullptr) return false;
    if (root->data == data) return true;
    else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}


int main() {
    bstNode *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 15);
    insert(root, 19);
    insert(root, 5);
    insert(root, 9);
    insert(root, 8);
    insert(root, 40);
    Delete(root, 40);

    bool res = search(root, 40);
    std::cout << res;
}