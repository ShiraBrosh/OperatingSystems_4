#include "Graph.hpp"

// Constructor to initialize graph with given number of vertices
Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}

// Function to add an edge from vertex v to vertex w
void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
}

// Function to remove an edge from vertex v to vertex w
void Graph::removeEdge(int v, int w) {
    adjList[v].remove(w);
}

// Function to print the graph
void Graph::printGraph() const {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << ":";
        for (auto v : adjList[i]) {
            std::cout << " -> " << v;
        }
        std::cout << std::endl;
    }
}
int main() {
    int numVertices = 5; // Example number of vertices
    Graph g(numVertices);

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Printing the graph
    g.printGraph();

    return 0;
}