/*
This is a header file for a hashmap implementation.

Study the function prototypes and the struct definitions to understand how the hashmap is implemented.

Do NOT modify this file.
*/

// A key value pair
// This is specifically for a (char*, int) key value pair
typedef struct pair {
    char *key;
    int value;
} pair_t;

// Each node holds a key and a value
typedef struct node {
    struct node *next;
    pair_t *kv;          // 'kv' stands for key/value pair
} node_t;

// Create a function prototype to a function that takes
// a char* and an int and returns an int
typedef int (*hashFunctionPointer)(char*, int);

// Chained implementation of a hashmap
typedef struct hashmap {
    unsigned int buckets;   // i.e. size of the hashmap
    node_t **arrayOfLists;  // An array of linked lists for our buckets
    // Read another way
    //      - an array of node_t*

    // A function pointer to a hash function
    // The hash_function must take in a 'char*' as a key, and have a
    // second parameter specifying the number of buckets.
    hashFunctionPointer hashFunction;
} hashmap_t;

// Simple hash function that will put a key into a bucket
int stringHash(char* myKey, int numberOfBuckets);

// Your hash function goes here
int yourHash(char* myKey, int numberOfBuckets);

// free a node
void free_node(node_t* node);

//copy a string
char* my_strcpy(const char* str);

//Given the number of buckets, create a hashmap
hashmap_t* hashmap_create(unsigned int _buckets);

//free the hashmap
void hashmap_delete(hashmap_t* _hashmap);

//check if the hashmap has a specific key
int hashmap_hasKey(hashmap_t* _hashmap, char* key);

//given the key and value, insert the pair to the hashmap
void hashmap_insert(hashmap_t* _hashmap, char* key, int value);

// given the key, retrieve the value from the hashmap
int hashmap_getValue(hashmap_t* _hashmap, char* key);

// remove a kv pair from the hashmap
void hashmap_removeKey(hashmap_t* _hashmap, char* key);

// print the kv pairs of the hashmap
void hashmap_printKeys(hashmap_t* _hashmap);
