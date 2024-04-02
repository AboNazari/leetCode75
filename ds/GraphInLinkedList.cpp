#include <iostream>
#include <vector>
using namespace std;

struct AdjListNode {
    int dest;
    AdjListNode* next;
};

struct AdjList {
    AdjListNode* head;
};

class Graph {
    // Using vector to store adjacency lists allows dynamic resizing
    vector<AdjList> array;

public:
    // Initially, the graph is empty
    Graph() {}

    // Function to add a vertex to the graph
    void addVertex() {
        AdjList newList;
        newList.head = nullptr;
        array.push_back(newList);
    }

    // Function to add an edge to graph
    void addEdge(int src, int dest) {
        // Ensure src and dest vertices exist
        if (src >= array.size() || dest >= array.size()) {
            cout << "Vertex does not exist." << endl;
            return;
        }

        // Add an edge from src to dest
        AdjListNode* newNode = new AdjListNode;
        newNode->dest = dest;
        newNode->next = array[src].head;
        array[src].head = newNode;

        // Since graph is undirected, add an edge from dest to src also
        newNode = new AdjListNode;
        newNode->dest = src;
        newNode->next = array[dest].head;
        array[dest].head = newNode;
    }

    // Function to print the adjacency list representation of graph
    void printGraph() {
        for (int v = 0; v < array.size(); ++v) {
            AdjListNode* pCrawl = array[v].head;
            cout << "\n Adjacency list of vertex " << v << "\n head ";
            while (pCrawl) {
                cout << "-> " << pCrawl->dest;
                pCrawl = pCrawl->next;
            }
            cout << endl;
        }
    }
};

// Driver program to test above functions
int main() {
    Graph graph;

    // Add vertices
    for (int i = 0; i < 5; ++i) {
        graph.addVertex();
    }

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the adjacency list representation of the above graph
    graph.printGraph();


    return 0;
}
