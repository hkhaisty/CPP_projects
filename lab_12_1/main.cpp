#include <vector>

using namespace std;

#include "Edge.h"
#include "Tree.h"
#include "graph.h"
#include <vector>
#include <queue>

using namespace std;

template<typename T>
Graph<T>::Graph() {
}

template<typename T>
Graph<T>::Graph(vector<T> vertices, int edges[][2],
                int numberOfEdges) {
    this->vertices = vertices;
    createAdjacencyLists(vertices.size(), edges, numberOfEdges);
}

template<typename T>
Graph<T>::Graph(int numberOfVertices, int edges[][2],
                int numberOfEdges) {
    for (int i = 0; i < numberOfVertices; i++)
        vertices.push_back(i); // vertices is {0, 1, 2, ..., n-1}
    createAdjacencyLists(numberOfVertices, edges, numberOfEdges);
}

template<typename T>
Graph<T>::Graph(vector<T> vertices, vector<Edge> edges) {
    this->vertices = vertices;
    createAdjacencyLists(vertices.size(), edges);
}

template<typename T>
Graph<T>::Graph(int numberOfVertices, vector<Edge> edges) {
    for (int i = 0; i < numberOfVertices; i++)
        vertices.push_back(i); // vertices is {0, 1, 2, ..., n-1}
    createAdjacencyLists(numberOfVertices, edges);
}

template<typename T>
void Graph<T>::createAdjacencyLists(int numberOfVertices,
                                    int edges[][2], int numberOfEdges) {
    for (int i = 0; i < numberOfVertices; i++) {
        neighbors.push_back(vector<int>(0));
    }
    for (int i = 0; i < numberOfEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        neighbors[u].push_back(v);
    }
}

template<typename T>
void Graph<T>::createAdjacencyLists(int numberOfVertices,
                                    vector<Edge> &edges) {
    for (int i = 0; i < numberOfVertices; i++) {
        neighbors.push_back(vector<int>(0));
    }
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        neighbors[u].push_back(v);
    }
}

template<typename T>
int Graph<T>::getSize() const {
    return vertices.size();
}

template<typename T>
int Graph<T>::getDegree(int v) const {
    return neighbors[v].size();
}

template<typename T>
T Graph<T>::getVertex(int index) const {
    return vertices[index];
}

template<typename T>
int Graph<T>::getIndex(T v) const {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == v)
            return i;
    }
    return -1; // If vertex is not in the graph
}

template<typename T>
vector<T> Graph<T>::getVertices() const {
    return vertices;
}

template<typename T>
vector<int> Graph<T>::getNeighbors(int v) const {
    return neighbors[v];
}

template<typename T>
void Graph<T>::printEdges() const {
    for (int u = 0; u < neighbors.size(); u++) {
        cout << "Vertex " << u << ": ";
        for (int j = 0; j < neighbors[u].size(); j++) {
            cout << "(" << u << ", " << neighbors[u][j] << ") ";
        }
        cout << endl;
    }
}

template<typename T>
void Graph<T>::printAdjacencyMatrix() const {
    int size = vertices.size();
    // Use vector for 2-D array
    vector<vector<int>> adjacencyMatrix(size);
    // Initialize 2-D array for adjacency matrix
    for (int i = 0; i < size; i++) {
        adjacencyMatrix[i] = vector<int>(size);
    }
    for (int i = 0; i < neighbors.size(); i++) {
        for (int j = 0; j < neighbors[i].size(); j++) {
            int v = neighbors[i][j];
            adjacencyMatrix[i][v] = 1;
        }
    }
    for (int i = 0; i < adjacencyMatrix.size(); i++) {
        for (int j = 0; j < adjacencyMatrix[i].size(); j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
Tree Graph<T>::dfs(int v) const {
    vector<int> searchOrders;
    vector<int> parent(vertices.size());
    for (int i = 0; i < vertices.size(); i++)
        parent[i] = -1; // Initialize parent[i] to -1
    // Mark visited vertices
    vector<bool> isVisited(vertices.size());
    for (int i = 0; i < vertices.size(); i++) {
        isVisited[i] = false;
    }
    // Recursively search
    dfs(v, parent, searchOrders, isVisited);
    // Return a search tree
    return Tree(v, parent, searchOrders);
}

template<typename T>
void Graph<T>::dfs(int v, vector<int> &parent,
                   vector<int> &searchOrders, vector<bool> &isVisited) const {
    // Store the visited vertex
    searchOrders.push_back(v);
    isVisited[v] = true; // Vertex v visited
    for (int j = 0; j < neighbors[v].size(); j++) {
        int i = neighbors[v][j];
        if (!isVisited[i]) {
            parent[i] = v; // The parent of vertex i is v
            dfs(i, parent, searchOrders, isVisited); // Recursive search
        }
    }
}

template<typename T>
Tree Graph<T>::bfs(int v) const {
    vector<int> searchOrders;
    vector<int> parent(vertices.size());
    for (int i = 0; i < vertices.size(); i++)
        parent[i] = -1; // Initialize parent[i] to -1
    queue<int> queue; // list used as a queue
    vector<bool> isVisited(vertices.size());
    queue.push(v); // Enqueue v
    isVisited[v] = true; // Mark it visited
    while (!queue.empty()) {
        int u = queue.front(); // Get the top element
        queue.pop(); // remove the top element
        searchOrders.push_back(u); // u searched
        for (int j = 0; j < neighbors[u].size(); j++) {
            int w = neighbors[u][j];
            if (!isVisited[w]) {
                queue.push(w); // Enqueue w
                parent[w] = u; // The parent of w is u
                isVisited[w] = true; // Mark it visited
            }
        }
    }
    return Tree(v, parent, searchOrders);
}
///////////////
#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "Edge.h"

using namespace std;

int main() {
    // Vertices for first graph
    string vertices[] = {"Seattle", "San Francisco", "Los Angeles",
                         "Denver", "Kansas City", "Chicago", "Boston", "New York",
                         "Atlanta", "Miami", "Dallas", "Houston"};
    // Edge array for first graph
    int edges[][2] = {
            {0,  1},
            {0,  3},
            {0,  5},
            {1,  0},
            {1,  2},
            {1,  3},
            {2,  1},
            {2,  3},
            {2,  4},
            {2,  10},
            {3,  0},
            {3,  1},
            {3,  2},
            {3,  4},
            {3,  5},
            {4,  2},
            {4,  3},
            {4,  5},
            {4,  7},
            {4,  8},
            {4,  10},
            {5,  0},
            {5,  3},
            {5,  4},
            {5,  6},
            {5,  7},
            {6,  5},
            {6,  7},
            {7,  4},
            {7,  5},
            {7,  6},
            {7,  8},
            {8,  4},
            {8,  7},
            {8,  9},
            {8,  10},
            {8,  11},
            {9,  8},
            {9,  11},
            {10, 2},
            {10, 4},
            {10, 8},
            {10, 11},
            {11, 8},
            {11, 9},
            {11, 10}
    };
    const int NUMBER_OF_EDGES = 46; //
    // Create vector for vertices
    vector<string> vectorOfVertices(12);
    copy(vertices, vertices + 12, vectorOfVertices.begin());
    Graph<string> graph1(vectorOfVertices, edges, NUMBER_OF_EDGES);
    cout << "The number of vertices in graph1: " << graph1.getSize();
    cout << "\nThe vertex with index 1 is " << graph1.getVertex(1);
    cout << "\nThe index for Miami is " << graph1.getIndex("Miami");
    cout << "\nedges for graph1: " << endl;
    graph1.printEdges();
    cout << "\nAdjacency matrix for graph1: " << endl;
    graph1.printAdjacencyMatrix();
    // vector of Edge objects for second graph
    vector<Edge> edgeVector;
    edgeVector.push_back(Edge(0, 2));
    edgeVector.push_back(Edge(1, 2));
    edgeVector.push_back(Edge(2, 4));
    edgeVector.push_back(Edge(3, 4));
    // Create a graph with 5 vertices
    Graph<int> graph2(5, edgeVector);
    cout << "The number of vertices in graph2: " << graph2.getSize();
    cout << "\nedges for graph2: " << endl;
    graph2.printEdges();
    cout << "\nAdjacency matrix for graph2: " << endl;
    graph2.printAdjacencyMatrix();
    Tree dfs = graph1.dfs(5); // Vertex 5 is Chicago
    vector<int> searchOrders = dfs.getSearchOrders();
    cout << dfs.getNumberOfVerticesFound() <<
         " vertices are searched in this DFS order:" << endl;
    for (int i = 0; i < searchOrders.size(); i++)
        cout << graph1.getVertex(searchOrders[i]) << " ";
    cout << endl << endl;
    for (int i = 0; i < searchOrders.size(); i++)
        if (dfs.getParent(i) != -1)
            cout << "parent of " << graph1.getVertex(i) <<
                 " is " << graph1.getVertex(dfs.getParent(i)) << endl;
    return 0;
}
////////////////