#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 5

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");

    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n",
               parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct the MST using Prim's Algorithm
void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from vertex 0
    key[0] = 0;
    parent[0] = -1;

    // MST will have V-1 edges
    for (int count = 0; count < V - 1; count++) {

        int u = minKey(key, mstSet);
        mstSet[u] = true;

        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] &&
                !mstSet[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    printf("Minimum Spanning Tree using Prim's Algorithm:\n");
    primMST(graph);

    return 0;
}