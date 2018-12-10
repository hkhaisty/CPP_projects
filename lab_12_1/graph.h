//
// Created by hkhai on 12/10/2018.
//

#ifndef LAB_12_1_GRAPH_H
#define LAB_12_1_GRAPH_H


#include <iostream>
using namespace std;

template<typename T>

class Graph {
public:
    /** Construct an empty graph */
    Graph();

    /** Construct a graph from vertices in a vector and
    * edges in 2-D array */
    Graph(vector<T> vertices, int edges[][2], int numberOfEdges);

    /** Construct a graph with vertices 0, 1, ..., n-1 and
    * edges in 2-D array */
    Graph(int numberOfVertices, int edges[][2], int numberOfEdges);

    /** Construct a graph from vertices and edges objects */
    Graph(vector<T> vertices, vector<Edge> edges);

    /** Construct a graph with vertices 0, 1, ..., n-1 and
    * edges in a vector */
    Graph(int numberOfVertices, vector<Edge> edges);

    /** Return the number of vertices in the graph */
    int getSize() const;

    /** Return the degree for a specified vertex */
    int getDegree(int v) const;

    /** Return the vertex for the specified index */
    T getVertex(int index) const;

    /** Return the index for the specified vertex */
    int getIndex(T v) const;

    /** Return the vertices in the graph */
    vector<T> getVertices() const;

    /** Return the neighbors of vertex v */
    vector<int> getNeighbors(int v) const;

    /** Print the edges */
    void printEdges() const;

    /** Print the adjacency matrix */
    void printAdjacencyMatrix() const;

    /** Obtain a depth-first search tree */
    Tree dfs(int v) const;

    /** Starting bfs search from vertex v */
    Tree bfs(int v) const;

protected:
    vector<T> vertices; // Store vertices
    vector<vector<int> > neighbors; // Adjacency lists
private:
    /** Create adjacency lists for each vertex from an edge array */
    void createAdjacencyLists(int numberOfVertices, int edges[][2],
                              int numberOfEdges);

    /** Create adjacency lists for each vertex from an Edge vector */
    void createAdjacencyLists(int numberOfVertices,
                              vector<Edge> &edges);

    /** Recursive function for DFS search */
    void dfs(int v, vector<int> &parent,
             vector<int> &searchOrders, vector<bool> &isVisited) const;
};

#endif //LAB_12_1_GRAPH_H
