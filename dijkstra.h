/*
 * This is the header file of dijkstra's shortest path
 */

// given an array of distance to the start city, an array of whether
// this node is visited, and the number of nodes, return the min. distance.
int minDistance(int dis[], int sptSet[],int numberOfNodes);

//if the shortest path is found, print from the start city to the destination city
//given the array that keeps track of the predecessor of each node, the destination 
//node's index, and the array that maps the indices to city names.
void printPath(int parent[], int dest, char** cityNames);

// consumes a malloced array (which is the adjacency matrix, the number of cities(nodes), 
// the index of the start city, the index of the destination city, and the array that 
// maps the indices to cityNames, print the final results :
// -if we can find a shortest path, print it and the distance.
// -else, show there are no paths between the cities.
void dijkstra(int* graph, int numberOfNodes, int src, int dest, char** cityNames);
