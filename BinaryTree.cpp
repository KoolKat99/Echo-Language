#include <iostream>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the binary tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        // If the tree is empty, create a new node
        return new TreeNode(value);
    }

    // Otherwise, insert the value in the appropriate subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an in-order traversal of the binary tree
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Create an empty binary tree
    TreeNode* root = nullptr;

    // Insert elements into the binary tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);

    // Perform in-order traversal and print the elements
    std::cout << "In-order Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}