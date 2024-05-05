/*
This is the header file of the adjacency matrix.
We will define the matrix's width before calling generateGraph.
*/


/*Given the malloced memory, generate an empty matrix 
 * given the number of row and columns .
 * Fill the matrix with 0.
 */

void generateGraph(int* g, int rows, int columns);


/*Given the malloced memory, number of rows and columns, 
 * indices of start node and end nde, distance between them, 
 * update the matrix
 */
void addEdge(int* g, int rows, int columns, int startNode, int endNode, int distance);

/* Given the malloced memory, number of rows and columns, 
 * print the matrix to check if it is right
 */

void printGraph(int* g, int rows, int columns);


/* Given the malloced memory, number of rows and columns, 
 * given the index of a node and return how many edges are into 
 * this node.
 */


int nodeInDegree(int* g, int rows, int columns, int node);


/* Given the malloced memory, number of rows and columns, 
 * given the index of a node and return how many edges are going out of
 * this node.
 */


int nodeOutDegree(int* g,int rows, int columns,  int node);


/* Given the malloced memory, number of rows and columns, 
 * given the index of two nodes and return a  1 if they are directly 
 * connected, 0 otherwise.
 */


int isConnected(int* g, int rows, int columns, int node1, int node2);
