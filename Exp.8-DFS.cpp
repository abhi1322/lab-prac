#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

// Function to perform Depth-First Search (DFS) on a graph represented using an adjacency list
void dfs(vector<vector<int>>& graph, int start) {
    // Create a stack for DFS traversal
    stack<int> st;

    // Create a set to keep track of visited vertices
    unordered_set<int> visited;

    // Push the start vertex onto the stack
    st.push(start);

    // Perform DFS traversal
    while (!st.empty()) {
        // Get the top vertex from the stack
        int current = st.top();
        st.pop();

        // If the current vertex has not been visited yet
        if (visited.find(current) == visited.end()) {
            // Mark the current vertex as visited
            visited.insert(current);
            cout << current << " ";

            // Visit all adjacent vertices of the current vertex
            for (int neighbor : graph[current]) {
                // If the neighbor has not been visited yet, push it onto the stack
                if (visited.find(neighbor) == visited.end()) {
                    st.push(neighbor);
                }
            }
        }
    }
}

int main() {
    // Example graph represented using an adjacency list
    vector<vector<int>> graph = {
        {},             // Node 0
        {2, 3},         // Node 1
        {4, 5},         // Node 2
        {6},            // Node 3
        {},             // Node 4
        {7},            // Node 5
        {8},            // Node 6
        {},             // Node 7
        {}              // Node 8
    };

    // Start DFS traversal from node 1
    cout << "DFS traversal starting from node 1: ";
    dfs(graph, 1);
    cout << endl;

    return 0;
}
