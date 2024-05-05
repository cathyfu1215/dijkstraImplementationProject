/*
 * This file contains functions that work for the adjacency matrix.
 */

#include "adjacencymatrix.h"

#include <stdio.h>
#include <stdlib.h>

/* This function generates an adjacency matrix for the cities
 It is empty (filled with 0s at the begining).
 It consumes the pointer to the malloced memory, and the number of rows and
columns.
*/

void generateGraph(int* g, int rows, int columns) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            g[i * rows + j] = 0;
        }
    }
}
/* This function  updates the graph when there is an edge betwwen the two nodes.
 It consumes the pointer to the malloced memory, the number of rows and
columns, the startNode, the endNode (both their indices) and an integer distance
value.
*/

void addEdge(int* g, int rows, int columns, int startNode, int endNode,
             int distance) {
    g[startNode * rows + endNode] = distance;
}

/* This function will print out the adjacency
 matrix for a graph.It consumes the pointer to the malloced memory, and the
number of rows and columns.

 */
void printGraph(int* g, int rows, int columns) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", g[i * rows + j]);
        }
        printf("\n");
    }
}

/* Compute 'in-degree' of a node
 For a given node 'n' in an adjacency matrix,
 compute the in-degree.It consumes the pointer to the malloced memory, and the
number of rows and columns, and the index of the node.

*/
int nodeInDegree(int* g, int rows, int columns, int node) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        if (g[i * rows + node] == 1) {
            count++;
        }
    }
    return count;
}

/* Compute 'out-degree' of a node
 For a given node 'n' in an adjacency matrix,
 compute the out-degree.It consumes the pointer to the malloced memory, and the
number of rows and columns,and the index of the node.
*/

int nodeOutDegree(int* g, int rows, int columns, int node) {
    int count = 0;
    for (int j = 0; j < columns; j++) {
        if (g[node * rows + j] == 1) {
            count++;
        }
    }
    return count;
}

/* Figure out if two nodes are connected
 Returns a 1 if node1 is connected to node 2
          It consumes the pointer to the malloced memory, and the
number of rows and columns,and the index of the nodes.

          */
int isConnected(int* g, int rows, int columns, int node1, int node2) {
    // return g[node1 * ROWS + node2] || g[node2 * ROWS + node1];
    // if we only consider one direction
    return g[node1 * rows + node2];
}
