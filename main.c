/*This is the driver file for HW #9 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// include your .h files here

#include "adjacencymatrix.c"
#include "dijkstra.c"
#include "my_hashmap.c"

// According to the requirement, there are less than or equal to 100 cities

#define MAX_CITIES 100

// According to the requirement, city name will not exceed 25 characters

#define MAX_CITY_NAME_SIZE 26

/**
 * Main program
 */
int main(int argc, char* argv[]) {
    char* fileNameCities = NULL;
    char* fileNameDistances = NULL;
    char* cityFrom = NULL;
    char* cityTo = NULL;

    // This code is provided to read the command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            if (i + 1 < argc) {
                fileNameCities = argv[++i];
            } else {
                printf("Missing argument for -c\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-d") == 0) {
            if (i + 1 < argc) {
                fileNameDistances = argv[++i];
            } else {
                printf("Missing argument for -d\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                cityFrom = argv[++i];
            } else {
                printf("Missing argument for -f\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-t") == 0) {
            if (i + 1 < argc) {
                cityTo = argv[++i];
            } else {
                printf("Missing argument for -t\n");
                return 1;
            }
        } else {
            printf("Unknown argument: %s\n", argv[i]);
            return 1;
        }
    }

    if (!fileNameCities || !fileNameDistances || !cityFrom || !cityTo) {
        printf(
            "Usage: %s -c <cities_file> -d <distances_file> -f <city_from> -t "
            "<city_to>\n",
            argv[0]);
        return 1;
    }

    //---------------------- your code here---------------
    int numberOfNodes = 0;

    // Create a hashmap that has keys of city names and values of the city's
    // line number from the cities files. According to the requirement, there
    // are no more than 100 cities.

    hashmap_t* cityLineNumberMap = hashmap_create(MAX_CITIES);

    // create an array of strings that contains city names , the indices are
    // their line number.This serves as a map where the key is the index, the
    // value is the city's name.

    char** cityIndexAndNames = malloc(MAX_CITIES * sizeof(char*));
    if (cityIndexAndNames == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    // Initialize each string in this array
    for (int i = 0; i < MAX_CITIES; i++) {
        cityIndexAndNames[i] = malloc(MAX_CITY_NAME_SIZE * sizeof(char));
        if (cityIndexAndNames[i] == NULL) {
            printf("Memory allocation failed.");
            exit(1);
        }
    }

    /*
     * This part opens the citiesX.dat file, read the lines, update
     * the map "cityName to lineNumber" and the map "lineNumber to cityName"
     * Also it counts how many lines are there in the file
     */
    FILE* file = fopen(fileNameCities, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    char line[MAX_CITY_NAME_SIZE];
    int lineNumber = 0;
    while (fscanf(file, "%s", line) == 1) {
        hashmap_insert(cityLineNumberMap, line, lineNumber);
        strcpy(cityIndexAndNames[lineNumber], line);
        lineNumber++;
        numberOfNodes++;
    }
    fclose(file);

    /*
     * Below we read from the distancesX.dat file and capture the edges between
     * our cities.
     */

    // malloc some memory, and
    // create an adjacency matrix
    int* adjMatrix = malloc(numberOfNodes * numberOfNodes * sizeof(int));

    generateGraph(adjMatrix, numberOfNodes, numberOfNodes);

    // read the distance file , add the edges to the adjacency matrix
    FILE* distfile;
    char startCity[MAX_CITY_NAME_SIZE];
    char endCity[MAX_CITY_NAME_SIZE];
    int distance;
    distfile = fopen(fileNameDistances, "r");
    if (distfile == NULL) {
        printf("Error openning the file\n");
        exit(1);
    }
    while (fscanf(distfile, "%s %s %d", startCity, endCity, &distance) == 3) {
        // in order to work with a matrix, convert the city's name to its index
        int startIndex = hashmap_getValue(cityLineNumberMap, startCity);

        int endIndex = hashmap_getValue(cityLineNumberMap, endCity);

        // add edge and capture its distance
        addEdge(adjMatrix, numberOfNodes, numberOfNodes, startIndex, endIndex,
                distance);
    }
    fclose(distfile);

    // run dijkstra from the start city to the end city, output the result
    // Again, convert the city names to their indices

    int indexOfFromCity = hashmap_getValue(cityLineNumberMap, cityFrom);
    int indexOfToCity = hashmap_getValue(cityLineNumberMap, cityTo);

    dijkstra(adjMatrix, numberOfNodes, indexOfFromCity, indexOfToCity,
             cityIndexAndNames);  // this function also prints the result

    // clean up everything and free the spaces
    free(adjMatrix);
    for (int i = 0; i < MAX_CITIES; i++) {
        free(cityIndexAndNames[i]);
    }
    free(cityIndexAndNames);
    hashmap_delete(cityLineNumberMap);

    return 0;
}
