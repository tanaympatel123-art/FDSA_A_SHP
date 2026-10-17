
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int code) {
    if (root == nullptr)
        return new Node(code);

    if (code < root->data)
        root->left = insert(root->left, code);
    else if (code > root->data)
        root->right = insert(root->right, code);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, code;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> code;
        root = insert(root, code);
    }

    cout << "Inorder sequence: ";
    inorder(root);

    cout << endl;
    return 0;
}
