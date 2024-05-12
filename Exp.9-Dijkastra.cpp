#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Define a structure to represent a graph edge
struct Edge {
    int destination;
    int weight;
};

// Define a structure to represent a vertex in the priority queue
struct Vertex {
    int node;
    int distance;

    // Constructor
    Vertex(int n, int d) : node(n), distance(d) {}

    // Overloading operator < for comparison in priority queue
    bool operator<(const Vertex& other) const {
        return distance > other.distance;
    }
};

// Function to perform Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices
void dijkstra(vector<vector<Edge>>& graph, int source) {
    int numVertices = graph.size();
    vector<int> distance(numVertices, INT_MAX); // Initialize distances to infinity
    vector<bool> visited(numVertices, false);   // Initialize visited array

    // Priority queue to store vertices with their distances
    priority_queue<Vertex> pq;

    // Distance to source vertex is 0
    distance[source] = 0;
    pq.push(Vertex(source, 0));

    while (!pq.empty()) {
        int u = pq.top().node;
        pq.pop();

        // Mark vertex as visited
        visited[u] = true;

        // Iterate through all adjacent vertices of u
        for (Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // Relaxation step
            if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(Vertex(v, distance[v]));
            }
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == INT_MAX)
            cout << "INFINITY";
        else
            cout << distance[i];
        cout << endl;
    }
}

int main() {
    // Example graph represented using an adjacency list
    vector<vector<Edge>> graph = {
        {{1, 4}, {2, 1}},       // Vertex 0
        {{2, 2}, {3, 5}, {4, 12}}, // Vertex 1
        {{3, 2}},               // Vertex 2
        {{4, 3}},               // Vertex 3
        {}                      // Vertex 4
    };

    int source = 0; // Source vertex

    // Perform Dijkstra's algorithm
    dijkstra(graph, source);

    return 0;
}
