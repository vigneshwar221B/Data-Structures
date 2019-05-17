#include <iostream>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node
{
    int data;
    Node *left, *right;
};

// Function to create a new binary tree node having given key
Node *newNode(int key)
{
    Node *node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

// Recursive function to insert an key into BST
void insert(Node *root, int key)
{
    // if the root is null, create a new node an return it
    if (root == nullptr)
        root = newNode(key);

    // if given key is less than the root node, recur for left subtree
    if (key < root->data)
        insert(root->left, key);

    // if given key is more than the root node, recur for right subtree
    else
        insert(root->right, key);
}

// Recursive function to search in given BST
bool search(Node *root, int key)
{
    // if key is not present in the key
    if (root == nullptr)
    {
        return false;
    }

    // if key is found
    if (root->data == key)
    {
        return true;
    }

    // if given key is less than the root node, recur for left subtree
    // else recur for right subtree

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Search given key in BST
int main()
{
    Node *root = nullptr;
    int keys[] = {15, 10, 20, 8, 12, 16, 25};

    for (int key : keys)
        insert(root, key);

    cout << search(root, 20);

    return 0;
}