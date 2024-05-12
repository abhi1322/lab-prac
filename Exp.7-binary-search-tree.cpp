#include <iostream>
using namespace std;

// Define Node structure for the Binary Search Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize data, left, and right pointers
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Define BinarySearchTree class
class BinarySearchTree
{
private:
    Node *root;

public:
    // Constructor to initialize root to nullptr
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a node into the BST
    Node *insert(Node *root, int value)
    {
        // If the tree is empty, create a new node as root
        if (root == nullptr)
        {
            root = new Node(value);
        }
        // If the value is less than the current node, insert into the left subtree
        else if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        // If the value is greater than or equal to the current node, insert into the right subtree
        else
        {
            root->right = insert(root->right, value);
        }
        return root;
    }

    // Function to insert a node into the BST (wrapper function)
    void insert(int value)
    {
        root = insert(root, value);
    }

    // Function to perform inorder traversal of the BST
    void inorderTraversal(Node *root)
    {
        if (root != nullptr)
        {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    // Function to perform inorder traversal of the BST (wrapper function)
    void inorderTraversal()
    {
        inorderTraversal(root);
    }
};

int main()
{
    // Create a Binary Search Tree object
    BinarySearchTree bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform inorder traversal to print the BST elements in sorted order
    cout << "Inorder traversal of BST: ";
    bst.inorderTraversal();
    cout << endl;

    return 0;
}
