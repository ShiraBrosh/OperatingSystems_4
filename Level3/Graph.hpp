#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <list>
#include <iostream>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void removeEdge(int v, int w);
    void printGraph() const;
    bool isEulerianCycle();  // Check if the graph has an Eulerian Cycle
    void findEulerianCycle();  
    void generateRandomGraph(int numEdges);
    
private:
    int vertices; // Number of vertices
    std::vector<std::list<int>> adjList; // Adjacency list representation
};

#endif
