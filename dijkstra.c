/*
 * This is the file of the dijkstra shortest path algorithms
 */

#include "dijkstra.h"

#include <limits.h>
#include <stdio.h>

/* Function to find the vertex with the minimum distance value
 * consumes the array that keeps track of other nodes' distance to
 * the start node, an array that marks wheter we have visited the
 * node already, and the number of nodes(cities)
 */
int minDistance(int dist[], int sptSet[], int numberOfNodes) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < numberOfNodes; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    // find the index of the node with the shorted distance, and
    // is unvisited(not done exploring).
    return min_index;
}

/* A recursive function to print the shortest path from source to target
 * if the current node's predecessor has an index of -1, it is the start node.
 * print it and it's done.
 * otherwise call this function but pass it's predecessor as a parameter, so it
 * is one step closer to the base case.
 * consumes an array that keeps track of the nodes' predecessors, the
 * destination node's index, and the array that maps indices to cityNames.
 */
void printPath(int parent[], int dest, char** cityNames) {
    if (parent[dest] == -1) {
        printf("%s\n", cityNames[dest]);
        return;  // the base case
    }
    printPath(parent, parent[dest], cityNames);
    printf("%s\n", cityNames[dest]);
}

/* Function to implement Dijkstra's algorithm
 * consumes an adjacency matrix, the number of cities(nodes),
 * the index of the start node, index of the destination node,
 * and the array that maps indices and cityNames.
 */
void dijkstra(int* graph, int numberOfNodes, int src, int dest,
              char** cityNames) {
    int dist[numberOfNodes];    // Stores the shortest distances from the source
    int parent[numberOfNodes];  // Stores the predecessor of each node
    int sptSet[numberOfNodes];  // Set to keep track of visited nodes(which is
                                // done exploring,
                                // so there is no need to update them)

    // initialize the arrays
    // if there is no path yet, assign the max int value to it
    // the start city's predecessor is index "-1"
    // at the beginning, no nodes are visited
    for (int i = 0; i < numberOfNodes; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
        sptSet[i] = 0;
    }

    // assign the start node's distance to itself zero
    dist[src] = 0;

    // total nodes :numberOfNodes
    // minus the starting node
    // so we have at most numberOfNodes steps to travel
    // for each of these steps, find the one with the shortest distance
    // then, mark it visited(done exploring)
    for (int count = 0; count < numberOfNodes - 1; count++) {
        int u = minDistance(dist, sptSet, numberOfNodes);
        sptSet[u] = 1;

        // for each neighbour of the known node u:
        // if the neighbour is not visited(not done exploring),
        // and there is a path between the known node u,
        // and the neighbour v, and the known node u is reachable from
        // the start node, and we found a shorter path that goes through the
        // known node u to v, than any other path from the start node to v, we
        // update the distance from start node to node v. also we mark v's
        // predecessor to u.
        for (int v = 0; v < numberOfNodes; v++) {
            if (!sptSet[v] && graph[u * numberOfNodes + v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u * numberOfNodes + v] < dist[v]) {
                dist[v] = dist[u] + graph[u * numberOfNodes + v];
                parent[v] = u;
            }
        }
    }

    // if there is a path, the distance should be less than int_max
    if (dist[dest] < INT_MAX) {
        // print the required results
        printf("Origin: %s\n", cityNames[src]);
        printf("Destination: %s\n", cityNames[dest]);
        printf("Distance: %d\n", dist[dest]);
        printf("Path cities:\n");
        printPath(parent, dest, cityNames);
    } else {
        // otherwise, there is no path between the two nodes
        printf("No path found from %s to %s\n", cityNames[src],
               cityNames[dest]);
    }
}
