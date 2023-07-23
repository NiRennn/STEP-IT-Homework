#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr){}
};

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }


    return root;
}

Node* findMinNode(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {

        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* minValueNode = findMinNode(root->right);
        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }

    return root;
}

Node* editNode(Node* root, int oldValue, int newValue) {
    root = deleteNode(root, oldValue);
    root = insertNode(root, newValue);
    return root;
}

void printVozr(Node* root) {
    if (root == nullptr) {
        return;
    }

    printVozr(root->left);
    cout << root->data << " ";
    printVozr(root->right);
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Base Tree: ";
    printVozr(root);
    cout << endl;

    root = deleteNode(root, 40);
    cout << "Tree after deleting element 40: ";
    printVozr(root);
    cout << endl;

    root = editNode(root, 30, 35);
    cout << "Tree after editing element 30 for 35: ";
    printVozr(root);
    cout << endl;


    return 0;
}
