# Dijkstra's Shortest Path Finder

This project is an implementation of Dijkstra’s algorithm to find the shortest path between two cities. It uses a graph representation of cities and their distances, which are provided in two separate data files.

## Problem Statement

The goal of this project is to help a visitor to several cities determine the shortest distance to reach a pair of cities. The distances in kilometres along train routes between each city of interest are provided.

## Data and Assumptions

The data for this project is in two files:
1. The first file contains the names of the cities in the map.
2. The second file contains the distances between the cities.

We are provided four datasets:
1. `cities0.dat` and `distances0.dat` contain an easy dataset with 5 “cities” (A, B, C, D, E) and 7 distances.
2. `cities1.dat` and `distances1.dat` contain a dataset with real cities in Europe and the distances between them.
3. `cities2.dat` and `distances2.dat` contain a dataset with some cities in Russia and the distances between them.
4. `cities3.dat` and `distances3.dat` contain a dataset with some cities in Canada and the distances between them.

Assumptions:
- There will never be more than 100 cities.
- There will never be more than 1000 distances.
- The names of the cities will be at most 25 characters long.
- Each city that is mentioned in the distances file will also be mentioned in the cities file.
- There may be pairs of cities that do not have any path between them.

## Program Behaviour

The program takes four command-line arguments:
1. `-c`: The name of the file that contains the names of the cities.
2. `-d`: The name of the file that contains the distances between the cities.
3. `-f`: The name of the “from”
4. `-t`: The name of the “to” city

### Example Run 1
```
$ ./main -c data/cities1.dat -d data/distances1.dat -f vienna -t munich
Origin: vienna
Destination: munich
Distance: 355
Path cities:
vienna
munich
```

### Example Run 2
```
$ ./main -c data/cities1.dat -d data/distances1.dat -f rome -t prague
Origin: rome
Destination: prague
Distance: 1431
Path cities:
rome
milan
munich
vienna
prague
```

### Example Run 3
```
$ ./main -c data/cities3.dat -d data/distances3.dat -f vancouver -t ottawa
Origin: vancouver
Destination: ottawa
Distance: 4820
Path cities:
vancouver
calgary
toronto
ottawa
```

### Example Run 4
```
./main -c data/cities2.dat -d data/distances2.dat -f volgograd -t chelyabinsk
Origin: volgograd
Destination: chelyabinsk
Distance: 3271
Path cities:
volgograd
rostov_on_don
moscow
kazan
ekaterinburg
chelyabinsk
```

### Example Run 5
```
$ ./main -c data/cities2.dat -d data/distances2.dat -f chelyabinsk -t volgograd
No path found from chelyabinsk to volgograd
```
