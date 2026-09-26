#include <stdio.h>
#include <stdbool.h>

#define V 4   // Number of vertices

int solutionCount = 0;

// Check if assigning color 'c' to vertex 'v' is safe
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

// Print the coloring solution
void printSolution(int color[]) {
    solutionCount++;

    printf("Solution %d:\n", solutionCount);
    for (int i = 0; i < V; i++)
        printf("Vertex %d -> Color %d\n", i, color[i]);

    printf("\n");
}

// Recursive utility function for graph coloring
void graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        printSolution(color);
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            graphColoringUtil(graph, m, color, v + 1);

            color[v] = 0; // Backtrack
        }
    }
}

// Main driver function
void graphColoring(int graph[V][V], int m) {
    int color[V] = {0};

    graphColoringUtil(graph, m, color, 0);

    if (solutionCount == 0)
        printf("No solution exists\n");
    else
        printf("Total solutions found: %d\n", solutionCount);
}

// Main function
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}