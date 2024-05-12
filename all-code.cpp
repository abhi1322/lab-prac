// Write a program to create a Stack and apply Push / Pop operations.


// Write a program to insert the elements with Binary Search Tree, and print.
#include <iostream>

using namespace std;

// Define the structure for a node in the BST
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize the node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
TreeNode *insert(TreeNode *root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to print the BST in an in-order traversal (left, root, right)
void printInOrder(TreeNode *root)
{
    if (root != nullptr)
    {
        printInOrder(root->left);
        cout << root->value << " ";
        printInOrder(root->right);
    }
}

int main()
{
    TreeNode *root = nullptr;
    int numElements, value;

    cout << "How many elements do you want to insert into the BST? ";
    cin >> numElements;

    for (int i = 0; i < numElements; i++)
    {
        cout << "Enter value to insert: ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-order traversal of the BST: ";
    printInOrder(root);
    cout << endl;

    return 0;
}

// Write a program to implement Depth-First-Search for graph

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform Depth-First Search
void DFS(vector<vector<int>> &graph, int startNode)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false); // To keep track of visited nodes
    stack<int> nodeStack;

    nodeStack.push(startNode);
    visited[startNode] = true;

    cout << "Depth-First Traversal starting from node " << startNode << ": ";

    while (!nodeStack.empty())
    {
        int currentNode = nodeStack.top();
        nodeStack.pop();
        cout << currentNode << " ";

        // Traverse all adjacent nodes of currentNode
        for (int adjacentNode : graph[currentNode])
        {
            if (!visited[adjacentNode])
            {
                nodeStack.push(adjacentNode);
                visited[adjacentNode] = true;
            }
        }
    }

    cout << endl;
}

int main()
{
    int numNodes, numEdges;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < numEdges; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    DFS(graph, startNode);

    return 0;
}

//