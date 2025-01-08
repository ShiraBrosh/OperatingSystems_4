#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <cstdlib>
#include <unistd.h>
#include <algorithm>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void removeEdge(int v, int w);
    void printGraph() const;
    bool isEulerianCycle();  // Check if the graph has an Eulerian Cycle
    void findEulerianCycle();  // Find and print the Eulerian Cycle
    void generateRandomGraph(int numEdges);  // Generate a random graph

private:
    int vertices; // Number of vertices
    std::vector<std::list<int>> adjList; // Adjacency list representation

    bool isConnected();  // Check if the graph is connected
    void DFSUtil(int v, std::vector<bool>& visited);  // Utility function for DFS
};

// Constructor to initialize graph with given number of vertices
Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}

// Function to add an edge from vertex v to vertex w
void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v);  // As the graph is undirected, add an edge from w to v as well
}

// Function to remove an edge from vertex v to vertex w
void Graph::removeEdge(int v, int w) {
    adjList[v].remove(w);
    adjList[w].remove(v);  // As the graph is undirected, remove the edge from w to v as well
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

// Function to check if the graph is connected
bool Graph::isConnected() {
    std::vector<bool> visited(vertices, false);

    // Find a vertex with a non-zero degree
    int startVertex = -1;
    for (int i = 0; i < vertices; ++i) {
        if (!adjList[i].empty()) {
            startVertex = i;
            break;
        }
    }

    // If there are no edges in the graph, return true (trivially Eulerian)
    if (startVertex == -1)
        return true;

    // Start DFS from a vertex with a non-zero degree
    DFSUtil(startVertex, visited);

    // Check if all vertices with non-zero degree are visited
    for (int i = 0; i < vertices; ++i) {
        if (!adjList[i].empty() && !visited[i])
            return false;
    }

    return true;
}

// Utility function for DFS traversal
void Graph::DFSUtil(int v, std::vector<bool>& visited) {
    visited[v] = true;
    for (int u : adjList[v]) {
        if (!visited[u]) {
            DFSUtil(u, visited);
        }
    }
}

// Function to check if the graph has an Eulerian Cycle
bool Graph::isEulerianCycle() {
    if (!isConnected())
        return false;

    // Check if all vertices with non-zero degree have even degree
    for (int i = 0; i < vertices; ++i) {
        if (adjList[i].size() % 2 != 0)
            return false;
    }

    return true;
}

// Function to find and print the Eulerian Cycle
void Graph::findEulerianCycle() {
    if (!isEulerianCycle()) {
        std::cout << "The graph does not have an Eulerian Cycle.\n";
        return;
    }

    // Use stack to store the path
    std::stack<int> stack;
    std::vector<int> eulerianCycle;
    std::vector<std::list<int>> tempAdjList = adjList;

    int startVertex = 0;
    stack.push(startVertex);

    while (!stack.empty()) {
        int v = stack.top();

        if (!tempAdjList[v].empty()) {
            int u = tempAdjList[v].front();
            stack.push(u);
            tempAdjList[v].remove(u);
            tempAdjList[u].remove(v);
        } else {
            eulerianCycle.push_back(v);
            stack.pop();
        }
    }

    // Print the Eulerian Cycle
    std::cout << "Eulerian Cycle: ";
    for (int v : eulerianCycle) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

// Function to generate a random graph with a given number of edges
void Graph::generateRandomGraph(int numEdges) {
    for (int i = 0; i < numEdges; ++i) {
        int v = rand() % vertices;
        int w = rand() % vertices;

        // Avoid loops and duplicate edges
        if (v != w && std::find(adjList[v].begin(), adjList[v].end(), w) == adjList[v].end()) {
            addEdge(v, w);
        } else {
            // Try again with different values if the edge was invalid
            --i;
        }
    }
}

int main(int argc, char* argv[]) {
    int numVertices = 5;  // Default number of vertices
    int numEdges = 10;    // Default number of edges
    int seed = time(nullptr); // Default seed based on current time

    // Parse command-line options using getopt
    int option;
    while ((option = getopt(argc, argv, "v:e:s:")) != -1) {
        switch (option) {
            case 'v':
                numVertices = std::stoi(optarg);
                break;
            case 'e':
                numEdges = std::stoi(optarg);
                break;
            case 's':
                seed = std::stoi(optarg);
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " -v numVertices -e numEdges -s seed\n";
                return 1;
        }
    }

    // Initialize random seed
    srand(seed);

    // Create and print a random graph
    Graph g(numVertices);
    g.generateRandomGraph(numEdges);
    g.printGraph();

    // Find and print the Eulerian Cycle if it exists
    g.findEulerianCycle();

    return 0;
}
