#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a structure to represent an edge in the graph
struct Edge {
    int source;
    int destination;
    int weight;

    // Constructor
    Edge(int src, int dest, int w) : source(src), destination(dest), weight(w) {}

    // Overloading operator < for sorting
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Define a structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent of a vertex using path compression technique
int findParent(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = findParent(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two sets using union by rank
void unionSets(vector<Subset>& subsets, int x, int y) {
    int xroot = findParent(subsets, x);
    int yroot = findParent(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskal(vector<Edge>& edges, int numVertices) {
    vector<Edge> result; // Stores the edges of the minimum spanning tree

    // Sort all edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end());

    // Allocate memory for creating subsets
    vector<Subset> subsets(numVertices);

    // Initialize each subset with its parent and rank
    for (int i = 0; i < numVertices; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Index variable used for sorted edges
    int i = 0;

    // Number of edges to be taken is equal to V-1
    while (result.size() < numVertices - 1 && i < edges.size()) {
        Edge nextEdge = edges[i++];

        int x = findParent(subsets, nextEdge.source);
        int y = findParent(subsets, nextEdge.destination);

        // If including this edge does not cause cycle, include it in result and increment the index
        if (x != y) {
            result.push_back(nextEdge);
            unionSets(subsets, x, y);
        }
    }

    // Print the edges of the minimum spanning tree
    cout << "Edges of the minimum spanning tree:\n";
    for (const Edge& edge : result) {
        cout << edge.source << " - " << edge.destination << " : " << edge.weight << endl;
    }
}

int main() {
    // Example graph represented using edge list
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int numVertices = 4; // Number of vertices in the graph

    // Perform Kruskal's algorithm
    kruskal(edges, numVertices);

    return 0;
}
